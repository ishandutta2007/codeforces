#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_pack
#define F first
#define S second

using namespace std;
ll x[1001];
ll y[1001];
long double f(int a,int b,int c)
{
    if (x[a]==x[c])
    {
        return (abs(x[b]-x[a]));
    }
    long double aa,bb,cc;
    aa=y[a];
    aa=(aa-y[c])/(x[a]-x[c]);
    bb=-1;
    cc=-1*(aa*x[a]+bb*y[a]);
    return (abs(aa*x[b]+bb*y[b]+cc)/(sqrt(aa*aa+bb*bb)));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(14) ;
    long double ans=1e10;

    int n,a,b,c;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>x[i]>>y[i];
    }
    for (int h=1; h<=n-2; h++)
    {
        if (ans>f(h-1,h,h+1)/2)
        {
            ans=f(h-1,h,h+1)/2;
        }
    }
    if (ans>f(n-2,n-1,0)/2)
    {
        ans=f(n-2,n-1,0)/2;
    }
    if (ans>f(n-1,0,1)/2)
    {
        ans=f(n-1,0,1)/2;
    }
    cout<<ans;
    // WTF GEO ?
}