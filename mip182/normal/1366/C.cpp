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
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int ranks[MAXN],par[MAXN],black[MAXN],white[MAXN];
int a[30][30];
void make_set(int s,bool ok)
{
    par[s]=s;
    ranks[s]=0;
    white[s]=0;
    black[s]=0;
    if (ok)
        white[s]++;
    else
        black[s]++;
}
int find_set(int s)
{
    if (par[s]==s)
        return s;
    return find_set(par[s]);
}
void union_sets(int u,int v)
{
    u=find_set(u);
    v=find_set(v);
    if (u!=v)
    {
        if (ranks[u]<ranks[v])
            swap(u,v);
        par[v]=u;
        if (ranks[u]==ranks[v])
            ranks[u]++;
        white[u]+=white[v];
        black[u]+=black[v];

    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        rep(i,n)
            rep(j,m)
            cin>>a[i][j];
        for (int i=0;i<n*m;i++)
            make_set(i,a[i/m][i%m]);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                for (int i1=0;i1<n;i1++)
                {
                    for (int j1=0;j1<m;j1++)
                    {
                        if (i+j==n-1-i1+m-1-j1&&i<=i1&&j<=j1)
                            union_sets(i1*m+j1,i*m+j);
                    }
                }
            }
        }
        int ans=0;
        for (int i=0;i<n*m;i++)
        {
            if (find_set(i)==i)
            {
                ans+=min(black[i],white[i]);
            }
        }
        cout<<ans<<'\n';
    }



    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
}