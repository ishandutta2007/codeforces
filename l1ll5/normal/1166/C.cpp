#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1005
#define ll long long
using namespace std;
#define mod 998244353
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define se second
#define fi first
#define lb lower_bound
#define ub upper_bound
ll n,ans;
vector<int> v;
map<int,int> p;
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int tmp=read();
        v.push_back(abs(tmp));
        p[abs(tmp)]++;
    }
    sort(v.begin(), v.end());
    for(auto k:v)
    {
        auto l=lb(v.begin(),v.end(),k);
        auto r=ub(v.begin(),v.end(),k*2);
        ans+=r-l;
    }
    for(auto pr:p)
    ans-=pr.se*pr.se-pr.se*(pr.se-1)/2;
    printf("%lld\n", ans);
    return 0;
}