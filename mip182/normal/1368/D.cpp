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
#define MANX MAXN


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
    int n;
    cin>>n;
    ll ans=0;
    vector <ll> a(n);
    rep(i,n) {
        cin >> a[i];
    }
    ll an=a[0];
    for (int i=1;i<n;i++)
        an&=a[i];
    vector <int> cnt(20);
    vector <ll> b(n,an);
    ll sum=0;
    for (int i=0;i<n;i++)
        a[i]^=an;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<20;j++)
        {
            if ((a[i]>>j)&1)
                cnt[j]++,sum++;
        }
    }
    int cur=0;
    while (true)
    {
        ll x=0;
        for (int i=0;i<20;i++)
        {
            if (cnt[i]>0)
                x^=(1<<i),cnt[i]--,sum--;
        }
        b[cur++]|=x;
        if (sum==0)
            break;
    }
    for (int i=0;i<n;i++)
        ans+=b[i]*b[i];
    cout<<ans;


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}