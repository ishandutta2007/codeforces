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
        vector <pair <int,int> > x(n);
        vector <vector <int> > y(1001);
        rep(i,n)
        cin>>x[i].fi>>x[i].se,y[x[i].se].pb(x[i].fi);
        for (int i=0;i<=1000;i++)
            sort(y[i].begin(),y[i].end());
        int cur=0;
        bool ok=true;
        string s="";
        int cnt=0;
        int i=0;
        while (y[i].size()==0)
            i++,cnt++;
        cur=0;
        for (;i<=1000;i++)
        {
            if (y[i].size())
            {
                if (cur>y[i][0])
                {
                    ok=false;
                    break;
                }
                while (cur<y[i][0])
                    s+='R',cur++;
                while (cnt)
                    s+='U',cnt--;
                for (int j=1;j<y[i].size();j++)
                {
                    while (cur<y[i][j])
                        s+='R',cur++;
                }
            }
            cnt++;

        }
        if (ok)
        {
            cout<<"YES\n";
            cout<<s<<'\n';
        }
        else
            cout<<"NO\n";
    }




}