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

int main() {
mipletsplay;
int h,w;
cin>>w>>h;
if (h==1&&w==1)
cout << 4;
else
{
if (h==1 && w==2)
cout << 8;
else{
if (h==2 && w==1)
cout << 8;
else
{
if (h==1 || w==1)
{
 ll answer=4;
 ll t=max(h,w);
 for (ll i=0;i<t-1;i++)
 {
   answer*=2;
   answer=answer%kek;
     
     
 }
 cout << answer;
    
    
}
else {
if (w%2==0 && h%2==0)
{
  ll answer=16;
  for (ll i=0;i<w/2-1;i++)
  {
    answer*=4;
    answer=answer%kek;
  }
  for (ll i=0;i<h/2-1;i++)
  {
    answer*=4;
    answer=answer%kek;
  }
  cout << answer; 
    
}
else
{
 if (w%2==0 || h%2==0)
 {
  ll answer=16;
  for (ll i=0;i<w/2-1;i++)
  {
    answer*=4;
    answer=answer%kek;
  }
  for (ll i=0;i<h/2-1;i++)
  {
    answer*=4;
    answer=answer%kek;
  }
  answer=answer*2;
  answer=answer%kek;
  cout << answer;   
     
     
     
     
     
     
     
     
     
     
 }
 else
 {
  ll answer=16;
  for (ll i=0;i<w/2-1;i++)
  {
    answer*=4;
    answer=answer%kek;
  }
  for (ll i=0;i<h/2-1;i++)
  {
    answer*=4;
    answer=answer%kek;
  }
  answer=answer*4;
  answer=answer%kek;
  cout << answer;   
     
     
     
     
     
     
     
     
 }
    
    
    
    
    
    
    
    
}}}}}}