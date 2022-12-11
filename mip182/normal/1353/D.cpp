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


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

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
     int n;
     cin>>n;
     vector <int> a(n);
     set <pair <int,pll> > s;
     s.insert({-n,{0,n-1}});
     for (int i=0;i<n;i++)
     {
         auto to=s.begin();
         int sz=-(*to).fi;
         int x=(*to).se.fi,y=(*to).se.se;
         s.erase(to);
         a[(x+y)/2]=i+1;
         if (sz==1)
         {
             a[x]=i+1;
             continue;
         }
         if (sz&1)
         {
             s.insert({-sz/2,{x,(x+y)/2-1}});
             s.insert({-sz/2,{(x+y)/2+1,y}});
         }
         else
         {
            if (sz/2-1>0)
                s.insert({-sz/2+1,{x,(x+y)/2-1}});
             s.insert({-sz/2,{(x+y)/2+1,y}});
         }
     }
     for (auto to:a)
         cout<<to<<" ";
     cout<<'\n';

    }
    
}