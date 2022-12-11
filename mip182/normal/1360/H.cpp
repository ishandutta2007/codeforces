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
ll bin_pow(ll base,ll deg)
{
    if (deg==0)
        return 1;
    ll t=bin_pow(base,deg/2);
    if (deg&1)
        return t*t*base;
    else
        return t*t;
}
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
        int n,m;
        cin>>n>>m;
        set <string> a;
        rep(i,n) {
            string ss;
            cin >> ss;
            a.insert(ss);
        }
        ll x=(bin_pow(2,m)-n+1)/2;
        for (int i=0;i<m;i++)
        {
            vector <string> err;
            ll cnt=bin_pow(2,m-i)/2;
            for (auto &to:a)
            {
                if (to[i]=='0')
                    cnt--;
            }
            if (x<=cnt)
            {
                for (auto &to:a)
                {
                    if (to[i]=='1')
                        err.pb(to);
                }
                cout<<0;
            }
            else
            {
                x-=cnt;
                for (auto &to:a)
                {
                    if (to[i]=='0')
                        err.pb(to);
                }
                cout<<1;
            }

            for (auto &to:err)
                a.erase(to);
        }
        cout<<'\n';


    }
}