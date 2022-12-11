#include <bits/stdc++.h>
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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define for0(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    ll n,l;
    cin>>n>>l;
    vector <ll> c(31,INFLL);
    for0(i,n)
    cin>>c[i];
    vector <ll> ct(36,0);
    ct[0]=c[0];
    for1(i,30)
    {
    ct[i]=min(c[i],ct[i-1]*2);
   // cout<<ct[i-1]*2<<'\n';
    }
    ll sum=0;
    for (ll i=0;i<30;i++)
    {
    if (sum>=ct[i])
        sum=ct[i];
    if (((l>>i)&1))
        sum+=ct[i];
    }
    cout<<sum;

}