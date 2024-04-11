#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vector <int> x={0,0,1,-1,1,1,-1,-1};
vector <int> y={1,-1,0,0,-1,1,-1,1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector <string> s(n);
    rep(i,n)
    cin>>s[i];
    int a[n+2][m+2];
    for (int i=0;i<n+2;i++)
    {
        a[i][0]=0;
        a[i][m+1]=0;
    }
    for (int i=0;i<m+2;i++)
    {
        a[0][i]=0;
        a[n+1][i]=0;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (s[i][j]=='*')
                a[i+1][j+1]=INF;
                        else{
                            if (s[i][j]=='.')
                                a[i+1][j+1]=0;
                            else
                            a[i+1][j+1]=s[i][j]-'0';
                }
        }
    }
    bool ok=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            int cnt=0;
            for (int f=0;f<8;f++)
            {
                if (a[i+x[f]][j+y[f]]==INF)
                    cnt++;
            }
            if (a[i][j]!=INF&&cnt!=a[i][j])
                ok=false;
        }
    }
    if (ok)
        cout<<"YES";
    else
        cout<<"NO";

}