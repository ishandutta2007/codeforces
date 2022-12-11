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
        string s;
        cin>>s;
        vector <vector <int> > rem(k);
        ll sum=0;
        for (int i=0;i<k;i++)
        {
            vector <int> a;
            a.pb(0);
            int now=0;
            for (int j=i;j<n;j+=k)
            {
                if (s[j]=='1')
                    now++,sum++;
                a.pb(now);
            }
            rem[i]=a;
//            cout<<i<<'\n';
//            for (auto to:a)
//                cout<<to<<" ";
//            cout<<'\n';
        }
        ll ans=sum;
        for (int i=0;i<k;i++)
        {
            int m=rem[i].size();
            ll now=sum-rem[i][m-1];
            ll will=rem[i][m-1];
            ll mx=0;
        //    cout<<i<<'\n';
            for (ll j=1;j<m;j++)
            {
            //    cout<<now<<" "<<mx<<" "<<-(2*rem[i][j]-j)<<" "<<now+mx+rem[i][m-1]-(2*rem[i][j]-j)<<'\n';
                ans=min(ans,now+mx+rem[i][m-1]-(2*rem[i][j]-j));
                mx=min(mx,(2*rem[i][j]-j));
            }
        }
        cout<<ans<<'\n';
    }
}