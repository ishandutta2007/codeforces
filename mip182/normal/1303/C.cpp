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
 //   ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int cnt=0;
        vector <int >col(26,0);
        for (int i=0;i<s.size();i++)
        {
            col[s[i]-'a']=1;
        }
        if (s.size()==1)
        {
            cout<<"YES\n";
            for (int i=0;i<26;i++)
            {
                cout<<(char)('a'+i);
            }
            cout<<'\n';
            continue;
        }
        if (s.size()==2)
        {
            cout<<"YES\n";
            cout<<s;
            for (int i=0;i<26;i++)
            {
                if ('a'+i!=s[0]&&'a'+i!=s[1])
                    cout<<(char)('a'+i);
            }
            cout<<'\n';
            continue;
        }
        vector <set<int> > g(26);
        for (int i=1;i<(int)(s.size())-1;i++)
        {
            g[s[i]-'a'].insert(s[i+1]-'a');
            g[s[i]-'a'].insert(s[i-1]-'a');
            g[s[i-1]-'a'].insert(s[i]-'a');
            g[s[i+1]-'a'].insert(s[i]-'a');
        }
        bool ko=true;
        for (int i=0;i<26;i++)
        {
            if (g[i].size()>2)
            {
                ko=false;
                break;
            }
        }
        if (ko==false)
        {
            cout<<"NO\n";
            continue;
        }
        string ans;
        int par=-1;
        int now=-1;
        int n=26;
        for (int i=0;i<n;i++)
        {
            if (g[i].size()==1)
                now=i;
        }
        if (now==-1)
        {
            cout<<"NO\n";
            continue;
        }
        vector <int> used(26,0);
        while (used[now]==0)
        {
         //   cout<<now<<'\n';
            ans+=(char)('a'+now);
            used[now]=1;
            int wasn=now;
            int wasp=par;
            cnt++;
            for (auto to:g[wasn])
            {
                if (to==wasp)
                    continue;
                else
                {

                    par=now;
                    now=to;
                }
            }
          //  cout<<ans<<'\n';
           // cout<<now<<" "<<par<<'\n';
        }
        for (int i=0;i<26;i++)
        {
            if (col[i]==0)
                ans+=(char)('a'+i),cnt++;
        }
      //  cout<<cnt<<'\n';
        if (ans.size()==26)
        {
            cout<<"YES\n";
            cout<<ans<<'\n';
        }
        else
            cout<<"NO\n";
    }




}