#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
            ll n;
            cin>>n;
            vector <ll> a(n),b(n);
            rep(i,n)
            cin>>a[i];
            rep(i,n)
            cin>>b[i];
            vector <ll> c(n);
            bool ok=false;
            rep(i,n) {
                c[i] = b[i] - a[i];
                if (c[i]<0)
                    ok=true;
            }
            if (ok)
            {
                cout<<"NO"<<'\n';
                continue;
            }
            int i=0;
            while (i<n&&c[i]==0)
                i++;
            if (i==n) {
                cout << "YES" << '\n';
                continue;
            }
            int q=c[i];
            while (i<n&&c[i]==q)
                i++;
            while (i<n&&c[i]==0)
                i++;
            if (i==n)
                cout<<"YES";
            else
                cout<<"NO";
            cout<<'\n';
    }}