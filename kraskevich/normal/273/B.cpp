#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

struct point
{
    int x,y;
    point() {}
    void read(int i) {scanf("%d",&x); y=i;}
};

bool cmp(point a, point b)
{
    return a.x<b.x;
}

const int N = 100 * 1000 * 2 + 100;
point p[N];
vector<int> temp;
long long mod;
long long ans=1;

void work()
{
    if(!temp.size())
        return;
    sort(temp.begin(),temp.end());
    int pr=0;
    for(int i=1;i<temp.size();++i)
        if(temp[i]==temp[i-1])
            ++pr;
    long long cur=1;
    for(long long i=1;i<=temp.size();++i)
    {
        long long mul=i;
        if(pr&&mul%2==0)
        {
            mul/=2;
            pr--;
        }
        cur*=mul;
        cur%=mod;
    }
    ans*=cur;
    ans%=mod;
}

void solve()
{
    int n;
    scanf("%d",&n);
    int sz=2*n;
    for(int i=0;i<n;++i)
        p[i].read(i+1);
    for(int i=0;i<n;++i)
        p[i+n].read(i+1);
    scanf("%I64d",&mod);
    sort(p,p+sz,cmp);
    for(int i=0;i<sz;++i)
    {
        if(i>0&&p[i].x!=p[i-1].x)
        {
            work();
            temp.clear();
        }
        temp.push_back(p[i].y);
    }
    work();
    printf("%I64d",ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();


    return 0;

}