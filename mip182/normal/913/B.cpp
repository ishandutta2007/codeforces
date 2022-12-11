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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define for0(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vector <int> g[1000];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    int n;
    cin>>n;
    vector <int> ff(n,0);
    for  (int i=0;i<n-1;i++)
    {
        int p;
        cin>>p;
        p--;
        g[i+1].pb(p);
        ff[p]=1;
    }
    vector <int> good(n,0);
    vector <int> counter(n,0);
    for (int i=0;i<n;i++)
    {
        if (g[i].size()==1&&ff[i]==0)
        {
            counter[g[i][0]]++;
            good[i]=1;
        }
    }
    for0(i,n)
    {
        if (counter[i]>=3)
            good[i]=1;
    }
    int cnt=0;
    for0(i,n)
    {
        if (good[i]==1)
            cnt++;
    }
    if (cnt==n)
        cout<<"Yes";
    else
        cout<<"No";



}