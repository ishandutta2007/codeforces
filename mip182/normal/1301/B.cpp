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
        vector <int> a(n);
        rep(i,n)
        cin>>a[i];
        int mx=0;
        for (int i=0;i<n-1;i++)
        {
            if (a[i]!=-1&&a[i+1]!=-1)
            {
                mx=max(mx,abs(a[i]-a[i+1]));
            }
        }
        vector <int> x;
        for (int i=0;i<n;i++)
        {
            if (a[i]==-1)
            {
                if (i>0&&a[i-1]!=-1)
                    x.pb(a[i-1]);
                if (i<n-1&&a[i+1]!=-1)
                    x.pb(a[i+1]);
            }
        }
        sort(all(x));
        int k=0;
        if (x.size()>0)
        {
            k=(x[0]+x[x.size()-1])/2;
            mx=max({mx,abs(k-x[0]),abs(k-x[x.size()-1])});
        }
        cout<<mx<<" "<<k<<'\n';
    }



}