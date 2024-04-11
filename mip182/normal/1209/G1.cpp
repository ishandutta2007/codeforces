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
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 2e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n,q;
    cin>>n>>q;
    vector <int> a(n);
    rep(i,n)
    cin>>a[i];
    vector <int> l(MAXN,INF),r(MAXN,-1);
    for (int i=0;i<n;i++)
    {
        l[a[i]]=min(l[a[i]],i);
        r[a[i]]=max(r[a[i]],i);
    }
    int i=0;
    int ans=0;
    while (i<n)
    {
        int j=i;
        int cnt=1;
        int mx=r[a[i]];
        map<int,int> mm;
        mm[a[i]]++;
        int xm=1;
        while (mx>j)
        {
           j++;
           mx=max(mx,r[a[j]]);
           mm[a[j]]++;
           xm=max(xm,mm[a[j]]);
           cnt++;
        }
        j++;
        i=j;
        ans+=cnt-xm;
    }
    cout<<ans;




}