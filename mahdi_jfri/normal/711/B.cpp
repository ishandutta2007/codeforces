#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const ll maxn=510;
bool x;
ll a[maxn][maxn];
ll sum[maxn],sumc[maxn];
ll sumd;
int main()
{
    ll n;
    cin>>n;
    ll i1=0,j1=0;
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 0)
                i1=i,j1=j;
            sum[i]+=a[i][j];
            sumc[j]+=a[i][j];
            if(i==j)
                sumd+=a[i][i];
        }
    }
    ll z=0;
    if(z==i1)
        z++;
    ll res=sum[z]-sum[i1];
    if(res<1)
    {
        if(n>1)
            cout<<-1;
        else
            cout<<1;
        return 0;
    }
    sum[i1]+=res;
    sumc[j1]+=res;
    a[i1][j1]=res;
    if(i1==j1)
        sumd+=res;
    for(ll i=0; i<n; i++)
    {
        if(sum[i]!=sum[i1])
        {
            cout<<"-1";
            return 0;
        }
    }
    for(ll i=0; i<n; i++)
    {
        if(sumc[i]!=sum[j1])
        {
            cout<<"-1";
            return 0;
        }
    }
    ll sumd2=0;
    ll n1=n-1;
    for(ll i=0; i<n; i++)
    {
        sumd2+=a[n1][i];
        n1--;
    }
    if(sumd2!=sumd || sumd2!=sum[j1] || sumd!=sum[i1])
    {
        cout<<"-1";
        return 0;
    }
    cout<<res;
}