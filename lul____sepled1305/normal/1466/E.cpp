/**
    Ithea Myse Valgulious
**/
 
#include<bits/stdc++.h>
#define ll long long
#define double long double
using namespace std;
using pii = pair<int,int>;
using pdd = pair<double,double>;
using pll = pair<ll,ll>;
int mod = 1e9+7;
int T;
 
ll qu[65];
 
ll sum(ll a, ll b)
{
    return (a+b)%mod;
}
 
ll mul(ll a,ll b)
{
    a%=mod;
    b%=mod;
    ll cur = (a*b)%mod;
    return cur;
}
 
void solve()
{
    int n,i,j;
    int bits[65];
    for(i=0;i<65;i++)
        bits[i] = 0;
    cin>>n;
    ll w[n];
    int br[n][65];
    for(i=0;i<n;i++)
    {
        cin>>w[i];
        for(j=0;j<61;j++)
        {
            if(w[i] & qu[j])
                bits[j]++,br[i][j] = 1;
            else
                br[i][j] = 0;
        }
    }
    ll su = 0;
    for(i=0;i<n;i++)
    {
        ll a=0, b=0;
        for(j=0;j<61;j++)
        {
            if(br[i][j])
                a = sum(a,mul(qu[j],bits[j]));
        }
        for(j=0;j<61;j++)
        {
            if(br[i][j])
                b = sum(b,mul(n,qu[j]));
            else
                b = sum(b,mul(bits[j],qu[j]));
        }
        //cout<<a<<' '<<b<<endl;
        su = sum(su,mul(a,b));
    }
    cout<<su<<"\n";
}
 
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll cur = 1;
    for(int i=0;i<61;i++)
    {
        qu[i] = cur;
        cur*=2;
    }
 
    cin>>T;
    while(T--)
        solve();
    return 0;
}