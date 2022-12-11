//#define _GLIBCXX_DEBUG
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
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=998244353;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n,k;
    cin>>n>>k;
    vector <int> a(n);
    rep(i,n)
        cin>>a[i];
    ll ans=0;
    for (int i=n;i>n-k;i--)
        ans+=i;
    cout<<ans<<' ';
    ll cnt=1;
    int i=0;
    while (i<n)
    {
        if (a[i]>n-k) {
            i++;
            continue;
        }
        int j=i;
        ll chet=0;
        while (j<n&&a[j]<=n-k)
            j++,chet++;
        if (i!=0&&j!=n)
            cnt*=chet+1;
        cnt%=mod1;
        i=j;
    }
    cout<<cnt;




}