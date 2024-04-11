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
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector <int> a(n);
    in(a);
    int l=1,r=n;
    int anss=-1;
    while (l<=r)
    {
        int mid=((l+r)>>1);
        vector <int> b(n);
        for (int i=0;i<n;i++)
        {
            if (a[i]>=mid)
                b[i]=1;
            else
                b[i]=0;
        }
        vector <int> pref(n+1);
        for (int i=1;i<=n;i++)
            pref[i]=pref[i-1]+b[i-1];
        vector <int> c(n+1);
        for (int i=1;i<=n;i++)
        {
            c[i]=2*pref[i]-i;
        }
        int mx_odd=INF;
        int mx_even=INF;
        bool ok=false;
//        cout<<mid<<'\n';
        for (int i=k;i<=n;i++){
            if (k%2==0)
                mx_odd=min(mx_odd,c[i-k]);
            else
                mx_even=min(mx_even,c[i-k]);
            ok|=c[i]>=mx_even;
            ok|=c[i]>=mx_odd+1;
//            cout<<c[i]<<" "<<mx_even<<" "<<mx_odd<<'\n';
            swap(mx_odd,mx_even);
        }
        if (ok)
            l=mid+1,anss=mid;
        else
            r=mid-1;
    }
    assert(anss!=-1);
    cout<<anss<<'\n';
}

int main() {
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}