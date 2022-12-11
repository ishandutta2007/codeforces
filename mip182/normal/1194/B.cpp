#include <bits/stdc++.h>
typedef long long ll;
#define gcd(x,y) __builtin_gcd(x,y)
#define numberof1(x) __builtin_popcount(x)
#define povsemelementam(i,mnozh) for(auto i: mnozh)
#define podotrezok(i,j) substr(i-1,j) // like prefix sum, (i,j)=s[j]-s[i-1]
#define pb push_back
#define pf push_front
#define popf pop_front
#define popb pop_back
#define eb emplace_back 
#define MP make_pair 
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 
#define REP(i, a, b) for (int i = a; i < b; i++)


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const int INF = 1e9;

int main() {
mipletsplay;

ll q;
cin>>q;
for (ll i=0;i<q;i++)
{
 ll n,m;
 cin >>n>>m;
 
 vector <string> s(n);
 vector <ll> a(n,0),b(m,0);
 for (ll j=0;j<n;j++)
 {
  cin >> s[j];
  for (ll u=0;u<m;u++)
  {
  if (s[j][u]=='*')    
    {
     a[j]++;
     b[u]++;
    }  
  }
 }
 ll answer=INF;
 for (ll q=0;q<n;q++)
 {
   for (ll p=0;p<m;p++)
   {
    if (s[q][p]=='.')
    answer=min(answer,n+m-a[q]-b[p]-1);
    else
    answer=min(answer,n+m-a[q]-b[p]);
       
       
       
       
       
       
   }
     
     
     
     
     
     
     
 }
 cout << answer<<endl;
 
 
 
 
 
 
}}