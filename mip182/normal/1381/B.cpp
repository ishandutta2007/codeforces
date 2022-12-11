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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN
#define itn int
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector <int> p(2*n+1);
        p[0]=0;
        rep(i,2*n)
        cin>>p[i+1];
        vector <vector <bitset<2001> > > dp(2*n+1,vector <bitset<2001> >(2));
        dp[0][1][0]=true;
        bool ok=false;
        for (int i=1;i<=2*n;i++)
        {
            int j=i-1;
            while (j>=0&&p[j]<p[i])
            {
                dp[i][0]|=dp[j][1];
                dp[i][1]|=(dp[j][0]<<(i-j));
                j--;
            }
            if (dp[i][1][n]||(n-(2*n-i+1)>=0&&dp[i][1][n-(2*n-i+1)]))
            {
                ok=true;
                break;
            }
        }
        if (ok||dp[2*n][1][n])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}