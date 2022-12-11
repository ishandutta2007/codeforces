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
ll n,m,k;
cin >>n>>m>>k;
ll answer=0;
deque <ll> d;
answer++;
ll t,f,chet=0,chet1=0;
cin >> f;
if (f%k==0)
t=f;
else
t=(f/k +1)*k;
chet++;
for (int i=1;i<m;i++)
{
  ll x;
  cin >> x;
  if (x-chet1<=t)
  chet++;
  else {
  if ((x-chet)%k==0)
  t=x-chet;
  else
  t=((x-chet)/k +1)*k;
  answer++;
  chet++;
  chet1=chet-1;
  }
      
      
      
      
      
      
  }
    
    
    

cout << answer;
}