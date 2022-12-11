#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define fi first
#define se second
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        bool ok=true;
        for (int i=0;i<s.size();i++)
        {
          if (s[i]=='?')
          {
              if (i==0){
                  if (s.size()==1)
                  {
                      s[i]='a';
                  }
                  else
                  {
                      if (s[i+1]!='a')
                          s[i]='a';
                      else
                          s[i]='b';
                  }
              }
              else
              {
                if (i==s.size()-1)
                {
                    if (s[i-1]!='a')
                        s[i]='a';
                    else
                        s[i]='b';
                }
                else
                {
                    if (s[i-1]!='?'&&s[i+1]!='?')
                    {
                        if (s[i-1]==s[i+1])
                        {
                            if (s[i-1]=='a')
                                s[i]='b';
                            else
                                s[i]='a';
                        }
                        else
                            s[i]='a'+'b'+'c'-s[i-1]-s[i+1];
                    }
                    else
                    {
                        char c='0';
                        if (s[i-1]!='?')
                            c=s[i-1];
                        else
                            c=s[i+1];
                        if (c=='a')
                            s[i]='b';
                        else
                            s[i]='a';
                    }
                }
              }
          }
          else
          {
              if ((i<s.size()-1&&s[i]==s[i+1])||(i>0&&s[i]==s[i-1])) {
                  ok = false;
                  break;
              }
          }
        }
        if (ok)
            cout<<s;
        else
            cout<<-1;
        cout<<'\n';
    }
}