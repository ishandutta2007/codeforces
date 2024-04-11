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
       vector <ll> a(n);
       rep(i,n)
       cin>>a[i];
       vector <ll> b(n);
       int cnt=0;
       rep(i,n) {
           cin >> b[i];
           if (b[i]==0)
               cnt++;
       }
       int left=INF,right=INF;
       for (int i=0;i<n;i++)
       {
           if (a[i]==1)
               left=min(left,i);
           if (a[i]==-1)
               right=min(right,i);
       }
       if (right==INF&&left==INF)
       {
           if (cnt!=n)
               cout<<"NO\n";
           else
               cout<<"YES\n";
           continue;
       }
       bool ok=true;
       for (int i=0;i<=min(right,left);i++)
       {
           if (a[i]!=b[i])
               ok=false;
       }
       if (left<right)
       {
               for (int i=left+1;i<=min(n-1,right);i++)
               {
                   if (a[i]>b[i])
                       ok=false;
               }
       } else
       {
           for (int i=right+1;i<=min(n-1,left);i++)
           {
               if (a[i]<b[i])
                   ok=false;
           }
       }
       if (ok)
           cout<<"YES\n";
       else
           cout<<"NO\n";


    }




}