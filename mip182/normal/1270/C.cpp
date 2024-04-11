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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define int long long

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        ll sum = 0, x = 0;
        rep(i, n) {
            cin >> a[i];
            sum += a[i];
            x ^= a[i];
        }
        x=(x<<((ll)1));
        ll b = 0;
        for (int i = 0; i < 61; i++) {
            if ((((x >> i) & 1) == 0) && (((sum >> i) & 1) == 1)) {
                b += (((ll)1) << i);
                sum += (((ll)1) << i);
                x ^= (((ll)1) << (i + 1));
            }
        }
        ll bb = 0;
        for (int i = 0; i < 61; i++) {
            if ((((x >> i) & 1) == 1) && (((sum >> i) & 1) == 0)) {
                bb += (((ll)1) << (i-1));
                sum+=(((ll)1)<<i);
            }
        }
    /*    ll summ=0,xx=0;
        for (int i=0;i<n;i++)
            summ+=a[i],xx^=a[i];
        summ+=b+2*bb,xx^=b;
        if (summ!=2*xx)
            cout<<"NOOOO"; /*/
        cout << 3 << '\n';
        cout << b << " " << bb << " " << bb << '\n';

    }


}