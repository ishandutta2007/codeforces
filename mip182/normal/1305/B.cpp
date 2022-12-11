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
    string s;
    cin>>s;
    int n=s.size();
    vector <vector <int> > ans;
    while (true)
    {
      int i=0,j=n-1;
      vector <int> ha;
      string k="";
      string g="";
      int cnt=0;
      while (i<n&&i<=j)
      {
        while (i<n&&i<=j&&s[i]==')')
            k+=s[i],i++;
        if (i==n||i>j)
            break;
        while (j>=0&&j>=i&&s[j]=='(')
            g+=s[j],j--;
        if (j==-1||j<i)
            break;
        cnt++;
        ha.pb(i);
        ha.pb(j);
        i++,j--;
      }
      if (cnt==0)
          break;
      ans.pb(ha);
      reverse(all(g));
      s=k+g;
      n=s.size();
    }
    cout<<ans.size()<<'\n';
    rep(i,ans.size())
    {
        cout<<ans[i].size()<<'\n';
        sort(all(ans[i]));
        rep(j,ans[i].size())
        cout<<ans[i][j]+1<<" ";
        cout<<'\n';
    }




}