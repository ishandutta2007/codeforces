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
        int n;
        cin>>n;
        vector <ll> a(n);
        rep(i,n)
        cin>>a[i];
        ll mx=0;
        bool ok=true;
        for (int i=0;i<n-1;i++)
        {
            if (a[i]>a[i+1])
                ok=false;
        }
        vector <ll> prefsuf(n+2,INFLL);
        for (int i=n;i>=1;i--)
            prefsuf[i]=min(prefsuf[i+1],a[i-1]);
        for (int i=0;i<n-1;i++)
        {
            mx=max(mx,a[i]-prefsuf[i+2]);
        }
        int cnt=0;
        while (mx)
        {
            mx/=2;
            cnt++;
        }
        cout<<cnt<<'\n';




    }



}