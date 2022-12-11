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
int dp[5001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    dp[0]=0;
    dp[1]=a;
    for (int j=2;j<=n;j++)
        dp[j]=INF;
    if (s.size()>1&&s[0]==s[1])
        dp[2]=min(dp[2],min(a+b,a+a));
    for (int i=2;i<=n;i++)
    {
        dp[i]=min(dp[i],dp[i-1]+a);
        if (i==n)
            continue;
        string t="";
        for (int j=i;j<n;j++)
        {
            t+=s[j];
        }
        t+='#';
        int g=t.size();
        for (int j=0;j<i;j++)
            t+=s[j];
        vector <int> pi(t.size(),0);
        for (int j=1;j<t.size();j++)
        {
            int f=pi[j-1];
            while (t[j]!=t[f]&&f!=0)
                f=pi[f-1];
            if (t[f]==t[j])
                f++;
            pi[j]=f;
            if (j>=g)
            {
                int x=f;
                if (x>0)
                {
                    dp[i+x]=min(dp[i+x],dp[i]+b);
                  //  cout<<i+x<<" "<<dp[i+x]<<'\n';
                  //  x=pi[x-1];
                }
            }
        }
    }
    cout<<dp[n];




}