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
        ll n,s;
        cin>>n>>s;
        vector <ll> a(n);
        rep(i,n)
            cin>>a[i];
        vector <ll> pref(n+1,0);
        map <ll,ll> m;
        rep(i,n)
            pref[i+1]=pref[i]+a[i];
        rep(i,n)
            m[pref[i+1]]=i+1;
        set <ll> ss;
        rep(i,n)
            ss.insert(pref[i+1]);
        if (pref[n]<=s)
        {
            cout<<0<<'\n';
            continue;
        }
        ll ans=-3;
        ll ind=1;
        for (int i=0;i<n;i++)
        {
            auto to=upper_bound(all(pref),s);
            if (to==pref.begin())
                continue;
            to=prev(to);
            if (m[*to]<i+1&&*to!=pref[i]) {
                if(ans<m[*to])
                    ans = max(ans, m[*to]),ind=i+1;
            }
            else
            {
                auto too=upper_bound(all(pref),s+a[i]);
                too=prev(too);
                if(ans<m[*too]-1)
                    ans = max(ans, m[*too]-1),ind=i+1;
            }

        }
        cout<<ind<<'\n';


    }



}