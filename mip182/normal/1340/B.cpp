//#define _GLIBCXX_DEBUG
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
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 2000+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vector <string> x={"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"};
bool dp[MAXN][MAXN];
int was[MAXN][MAXN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int n,k;
    cin>>n>>k;
    vector <string> ss(n);
    rep(i,n)
    cin>>ss[i];
    reverse(all(ss));
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        string s=ss[i-1];
        for (int j=0;j<10;j++)
        {
            bool ok=true;
            int cnt=0;
            for (int f=0;f<7;f++)
            {
                if (s[f]=='1'&&x[j][f]=='0')
                {
                    ok=false;
                }
                else
                {
                    if (s[f]!=x[j][f])
                        cnt++;
                }
            }
            if (!ok)
                continue;
            for (int f=0;f<=k-cnt;f++)
            {
                if (dp[i][f+cnt]==false&&dp[i-1][f]==true)
                {
                    dp[i][f+cnt]=true;
                    was[i][f+cnt]=f;
                }
            }

        }
    }
    if (dp[n][k]==false)
    {
        cout<<-1;
        return 0;
    }
    int now=k;
    for (int i=n;i>=1;i--)
    {
        for (int j=9;j>=0;j--)
        {
            bool ok=true;
            int cnt=0;
            for (int f=0;f<7;f++)
            {
                if (ss[i-1][f]=='1'&&x[j][f]=='0')
                {
                    ok=false;
                }
                else
                {
                    if (ss[i-1][f]!=x[j][f])
                        cnt++;
                }
            }
            if (!ok)
                continue;
            if (now-cnt>=0&&dp[i-1][now-cnt]==true)
            {
                now-=cnt;
                cout<<j;
                break;
            }
        }
    }




}