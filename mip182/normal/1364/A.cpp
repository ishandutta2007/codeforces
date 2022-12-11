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
int main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
   int t;
   cin>>t;
   while (t--)
   {
        int n,x;
        cin>>n>>x;
        vector <int> a(n);
        int cnt=0;
        ll sum=0;
        rep(i,n){
        cin>>a[i];
        if (a[i]%x==0)
        cnt++;
        sum+=a[i];
        }
        if (cnt==n)
        cout<<-1<<'\n';
        else
        {
              if (sum%x)
              cout<<n<<'\n';
              else
              {
                   int a1=0;
                   while (a[a1]%x==0)
                   a1++;
                   int a2=0;
                   int f=n-1;
                   while (a[f]%x==0)
                   a2++,f--;
                   cout<<max(n-a1-1,n-a2-1)<<'\n';
              }
        }
   }
      
}