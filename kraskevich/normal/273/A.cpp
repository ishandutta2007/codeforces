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

#define set SETETETT

const int N = 100 * 1000 + 10;
long long t[4*N];
long long add[4*N];
long long a[N];

void init()
{
    fill(t,t+4*N,0);
    fill(add,add+4*N,0);
}

long long getMax(int pos, int l, int r, int tl, int tr, long long curMax)
{
    curMax=max(curMax,add[pos]);
    if (l==tl&&r==tr)
        return max(t[pos],curMax);
    int cl = 2 * pos + 1, cr = 2 * pos + 2;
    int m = (tl + tr) / 2;
    long long ml = 0;
    long long mr = 0;
    if(l<=m)
        ml=getMax(cl,l,min(r,m),tl,m,curMax);
    if(r>m)
        mr=getMax(cr,max(l,m+1),r,m+1,tr,curMax);
    return max(ml,mr);
}

void set(int pos, int l, int r, int tl, int tr, long long val)
{
    if (l==tl&&r==tr)
    {
        add[pos]=t[pos]=val;
        return;
    }
    int cl=2*pos+1,cr=2*pos+2;
    int m=(tl+tr)/2;
    if(l<=m)
        set(cl,l,min(r,m),tl,m,val);
    if(r>m)
        set(cr,max(l,m+1),r,m+1,tr,val);
    t[pos]=max(t[cl],t[cr]);
}

void solve()
{
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    init();
    for(int i=0;i<n;++i)
        set(0,i,i,0,N-1,a[i]);
    int m;
    cin >> m;
    for (int i=0;i<m;++i)
    {
        long long w,h;
        cin>>w>>h;
        long long low=getMax(0,0,w-1,0,N-1,0);
        cout << low << "\n";
        set(0,0,w-1,0,N-1,low+h);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();


    return 0;

}