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
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if (n*a!=m*b) {
            cout << "No\n";
            continue;
        }
        cout<<"Yes\n";
        vector <vector <int> > ans(n,vector <int>(m));
        vector <int> cnt(n);
        set <pii> s;
        for (int i=0;i<n;i++)
            s.insert({-a,i});
        for (int i=0;i<m;i++)
        {
            vector <pii> add;
            for (int j=0;j<b;j++)
            {
                auto to=s.begin();
                int x=(*to).fi,y=(*to).se;
                assert(x!=0);
                add.pb({x+1,y});
                ans[y][i]=1;
                s.erase(to);
            }
            for (auto to:add)
                s.insert(to);
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
                cout<<ans[i][j];
            cout<<'\n';
        }
    }
}