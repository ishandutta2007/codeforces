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
const int MAXN = 26+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int par[MAXN],sz[MAXN];
void make_set(int s)
{
    par[s]=s;
    sz[s]=1;
}
int find_set(int s)
{
    if (par[s]==s)
        return s;
    return par[s]=find_set(par[s]);
}
void union_sets(int u,int v)
{
    u=find_set(u);
    v=find_set(v);
    if (u!=v)
    {
        if (sz[u]<sz[v])
            swap(u,v);
        par[v]=u;
        sz[u]+=sz[v];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in","r",stdin);
    #endif
    int _t;
    cin>>_t;
    while (_t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        for (int i=0;i<20;i++)
            make_set(i);
        bool ok=true;
        for (int i=0;i<n;i++)
        {
            if (a[i]>b[i])
            {
                ok=false;
                break;
            }
        }
        if (!ok)
        {
            cout<<-1<<'\n';
            continue;
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            if (a[i]==b[i])
                continue;
            union_sets(a[i]-'a',b[i]-'a');
        }
        for (int i=0;i<20;i++)
        {
            if (find_set(i)==i)
                ans+=sz[i]-1;
        }
        cout<<ans<<'\n';
    }


    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}