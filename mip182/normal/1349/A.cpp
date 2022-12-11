//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
ll bin_pow(ll base,ll deg)
{
    if (deg==0)
        return 1;
    ll t=bin_pow(base,deg/2);
    if (deg&1)
        return (t*t)*base;
    else
        return (t*t);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int n;
    cin>>n;
    vector <int> a(n);
    rep(i,n)
    cin>>a[i];
    vector <int>  first(2e5+1,-1);
    vi sec(2e5+1,-1);
    vi counter(2e5+1,0);
    for (int i=0;i<n;i++)
    {
        for (int j=2;j*j<=a[i];j++)
        {
            if (a[i]%j==0)
            {
                int cnt=0;
                while (a[i]%j==0)
                    cnt++,a[i]/=j;
                counter[j]++;
                if (first[j]==-1)
                    first[j]=cnt;
                else
                {
                    if (first[j]>=cnt)
                        sec[j]=first[j],first[j]=cnt;
                    else
                    {
                        if (sec[j]==-1||sec[j]>=cnt)
                            sec[j]=cnt;
                    }
                }
            }
        }
        if (a[i]>1)
        {
           int cnt=1;
           int j=a[i];
            counter[j]++;
            if (first[j]==-1)
                first[j]=cnt;
            else
            {
                if (first[j]>=cnt)
                    sec[j]=first[j],first[j]=cnt;
                else
                {
                    if (sec[j]==-1||sec[j]>=cnt)
                        sec[j]=cnt;
                }
            }
        }
    }
    ll ans=1;
   // cout<<counter[5]<<'\n';
    for (int i=2;i<=2e5;i++)
    {
        if (counter[i]>0)
        {
            if (counter[i]<=n-2)
                continue;
           // cout<<i<<" "<<counter[i]<<'\n';
            if (counter[i]==n-1)
                ans*=bin_pow(i,first[i]);
            else
                ans*=bin_pow(i,sec[i]);
        }
    }
    cout<<ans;




}