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
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
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
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector <int> a(n);
        rep(i,n)
        cin>>a[i];
        ll ans=n/2;
        vector <int> cnt(2*k+1);
        vector <int> minx(2*k+1),maxx(2*k+1);
        rep(i,n/2)
        {
            cnt[a[i]+a[n-1-i]]++;
            minx[min(a[i],a[n-1-i])+1]++;
            maxx[max(a[i],a[n-1-i])+k]++;
        }
        vector <int> prefmin(2*k+1),prefmax(2*k+1);
        for (int i=1;i<=2*k;i++)
            prefmin[i]=prefmin[i-1]+minx[i],prefmax[i]=prefmax[i-1]+maxx[i];
        for (int i=2;i<=2*k;i++)
        {
            ll chet=n/2;
            chet+=prefmax[i-1]+prefmin[2*k]-prefmin[i];
            chet-=cnt[i];
            ans=min(ans,chet);

        }
        cout<<ans<<'\n';
    }




}