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
    int n;
    cin>>n;
    vector <pii> a;
    {
        vector <int> c(n);
        in(c);
        int i=0;
        while (i<n){
            int j=i;
            int cnt=0;
            while (j<n&&c[i]==c[j])
                cnt++,j++;
            cnt=min(cnt,2);
            a.pb({c[i],cnt});
            i=j;
        }
    }
    n=a.size();
    int ans=0;
    int st=0;
    while (st<n&&a[st].se==1)
        ans++,st++;
    if (st==n)
    {
        cout<<ans<<'\n';
        return;
    }
    ans+=2;
    while (st<n){
        int nex=st+1;
        while (nex<n&&a[nex].se==1)
            nex++;
        if (nex==n)
        {
            ans+=nex-st-1;
        }
        else
        {
            if (a[st].fi!=a[nex].fi)
            {
                ans+=nex-st-1+2;
            }
            else
            {
                int chet=0;
                int cnt=0;
                for (int i=st+2;i<nex;i+=2)
                    chet+=a[i].fi==a[st].fi,cnt++;
                if (chet==cnt)
                {
                    ans+=nex-st-1+1;
                }
                else
                    ans+=nex-st-1+2;
            }
        }
        st=nex;
    }
    cout<<ans<<'\n';
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