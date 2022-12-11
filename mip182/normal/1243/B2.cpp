#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin>>k;
    while (k--) {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        vector <int> a(26),b(26),c(26);
        for (int i=0;i<n;i++)
        {
            a[s[i]-'a']++;
            a[t[i]-'a']++;
            b[s[i]-'a']++;
            c[t[i]-'a']++;
        }
        bool ok=true;
        for (int i=0;i<26;i++)
        {
            if ((a[i]%2)!=0)
                ok=false;
        }
        if (ok)
        {
            int cnt=0;
            vector <pii > ans;
            while (cnt<n)
            {
                if (s[cnt]==t[cnt]) {
                    b[s[cnt]-'a']--;
                    c[t[cnt]-'a']--;
                }
                else
                {
                  if (b[s[cnt]-'a']>1)
                  {
                      for (int i=n-1;i>=0;i--)
                      {
                          if (s[i]==s[cnt])
                          {
                              ans.pb({i,cnt});
                               c[t[cnt]-'a']--;
                               b[s[cnt]-'a']--;
                               b[s[i]-'a']--;
                               b[t[cnt]-'a']++;
                              swap(t[cnt],s[i]);
                              break;
                          }
                      }
                  } else
                  {
                      for (int i=n-1;i>=0;i--) {
                          if (t[i] == s[cnt]) {
                              b[s[i]-'a']--;
                              c[t[i]-'a']--;
                              b[t[i]-'a']++;
                              c[s[i]-'a']++;
                              ans.pb({i,i});
                              swap(t[i],s[i]);
                              ans.pb({i,cnt});
                              c[t[cnt]-'a']--;
                              b[t[cnt]-'a']++;
                              b[s[cnt]-'a']-=2;

                              swap(s[i],t[cnt]);
            break;
                          }
                      }

                  }
                }
                cnt++;
            }
            cout<<"Yes"<<'\n';
            cout<<ans.size()<<'\n';
            for (int i=0;i<ans.size();i++)
                cout<<ans[i].first+1<<" "<<ans[i].second+1<<'\n';
        } else
            cout<<"No"<<'\n';


    }}