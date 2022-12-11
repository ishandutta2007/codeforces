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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define int long long

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
     freopen("a.in","r",stdin);
     freopen("a.out","w",stdout);
    #endif
     int t;
     cin>>t;
     while (t--)
     {
         int n;
         cin>>n;
         vector <int> a(n);
         map <int,int> m;
         vector <int> b;
         rep(i,n)
         {
             cin>>a[i];
             m[a[i]]++;
         }
         for (auto to:m)
         {
             if (to.second>=4)
             {
                 b.pb(to.first);
                 b.pb(to.first);
             } else
             {
                 if (to.second>=2)
                 {
                     b.pb(to.first);
                 }
             }
         }
         pair <int,int> answer;
         pair <int,int> ans={INF,1};
         for (int i=0;i<b.size()-1;i++)
         {
            if (ans.first*(b[i]*b[i+1])>((b[i]*b[i]+b[i+1]*b[i+1]))*ans.second)
                ans={((b[i]*b[i]+b[i+1]*b[i+1])),(b[i]*b[i+1])},answer={b[i],b[i+1]};
         }
         cout<<answer.first<<" "<<answer.first<<" "<<answer.second<<" "<<answer.second<<'\n';
     }




}