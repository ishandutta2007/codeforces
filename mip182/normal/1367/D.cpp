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
#define MANX MAXN


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
    int q;
    cin>>q;
    while (q--)
    {
        string s;
        cin>>s;
        int n=s.size();
        int m;
        cin>>m;
        vector <int> b(m);
        int f=0;
        rep(i,m) {
            cin >> b[i];
            if (b[i]==0)
                f++;
        }
        vector <int> cnt(26);
        for (auto to:s)
            cnt[to-'a']++;
        string ans;
        for (int i=0;i<m;i++)
            ans+='#';
        vector <pair <int,vi> > sz;
        vector <int> used(n);
        while (true)
        {
            int chet=0;
            vector <int> add;
            for (int i=0;i<m;i++)
            {
                if (used[i])
                    continue;
                int sum=0;
                for (int j=0;j<m;j++)
                {
                    if (used[j])
                        sum+=abs(i-j);
                }
                if (sum==b[i])
                    chet++,add.pb(i);
            }
            if (chet==0)
                break;
            sz.pb({chet,add});
            for (auto to:add)
                used[to]=1;
        }
        int cur=25;
        for (int i=0;i<sz.size();i++)
        {
            while (cnt[cur]<sz[i].fi)
                cur--;
            for (auto to:sz[i].se)
                ans[to]=(char)('a'+cur);
         //   cout<<i<<" "<<cur<<" "<<ans<<'\n';
            cur--;
        }
        cout<<ans<<'\n';
    }


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}