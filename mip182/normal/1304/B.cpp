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
    int n,m;
    cin>>n>>m;
    vector <string> s(n);
    rep(i,n)
    cin>>s[i];
    map <string,int> mm;
    for (int i=0;i<n;i++)
        mm[s[i]]++;
    string ans="";
    map <string,int> used;
    map <string,int> there;
    for (int i=0;i<n;i++)
        there[s[i]]++;
    map <string,int> mmm=mm;
    for (auto to:mmm)
    {
        string ss=to.fi;
        reverse(ss.begin(),ss.end());
        bool ok=true;
        for (int j=0;j<m/2;j++)
        {
            if (ss[j]!=ss[m-1-j])
                ok=false;
        }
        if (ok)
        {
            used[to.fi]=mm[to.fi]/2;
            for (int i=0;i<mm[to.fi]/2;i++)
            {
                ans+=to.fi;
            }
            continue;
        }

      // cout<<to.fi<<" "<<max(mm[to.fi],mm[ss])<<'\n';
        if (min(mm[to.fi],mm[ss])>=1&&used[to.fi]==0&&used[ss]==0)
        {
            used[to.fi]=min(mm[to.fi],mm[ss]);
            used[ss]=min(mm[to.fi],mm[ss]);
            for (int i=0;i<min(mm[to.fi],mm[ss]);i++)
            {
                ans+=to.fi;
            }
        }
    }
    string mb="";
    for (int i=0;i<n;i++)
    {
        bool ok=true;
        for (int j=0;j<m/2;j++)
        {
            if (s[i][j]!=s[i][m-1-j])
                ok=false;
        }
        if (ok&&used[s[i]]!=there[s[i]]) {
            mb=s[i];
        break;}
    }
    cout<<ans.size()+ans.size()+mb.size()<<'\n';
    cout<<ans;
    cout<<mb;
    reverse(all(ans));
    cout<<ans;







}