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
const ll kek=998244353;
ll power(ll x,ll y)
{
   ll answer=1;
   while (y>0)
   {
    answer=(answer*x)%kek;
    y--;
       
       
       
       
   }
   return answer; 
    
    
    
}
 
 
int main() {
mipletsplay;
ll n,answer=0;
cin >>n;
for (ll i=0;i<n;i++)
{
  ll a,j=0;
  cin >> a;
  while (a!=0)
  {
  //answer+=((((a%10)*pow(10,j)+(a%10)*pow(10,j+1))%kek)*n)%kek;
  ll x=(a%10)*power(10,j)+(a%10)*power(10,j+1);
  x=(x%kek+kek)%kek;
  x=x*n;
  x=(x%kek+kek)%kek;
  answer+=x;
  answer=(answer%kek +kek)%kek;
  j+=2;
  a=a/10;
  }
}
cout << answer;}