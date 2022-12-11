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
int b,k;
cin >>b>>k;
if ((b&1)==0)
{
ll x; for (int i=0;i<k-1;i++)   
  cin >> x;
  ll y;
  cin >> y;
  if ((y&1)!=0)
  cout << "odd";
  else
  cout << "even";
}  
else
{
 int sum=0;
 for (int i=0;i<k;i++)
 {
int x;
cin >>x;
if ((x&1)==1)
sum++;
     
     
 }
 if ((sum&1)!=0)
 cout << "odd";
 else
 cout <<"even";
    
    
}
}