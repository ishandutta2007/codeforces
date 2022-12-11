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
ll n;
cin >>n;
vector <ll> a(n+2),b(n+2);
ll dp[n+2][2];
for (int i=0;i<n+2;i++)
{
  for (int j=0;j<2;j++)
  dp[i][j]=0;
    
    
    
}
for (int i=0;i<n;i++)
cin >>a[i];
a[n]=0;
b[n]=0;
for (int i=0;i<n;i++)
cin >>b[i];
dp[0][0]=a[0];
dp[0][1]=b[0];
for (int i=0;i<n-1;i++)
{
 
  dp[i+2][0]=max(dp[i][0]+b[i+1]+a[i+2],dp[i+2][0]);
  dp[i+1][1]=max(dp[i][0]+b[i+1],dp[i+1][1]);
  dp[i+2][1]=max(dp[i][0]+b[i+2],dp[i+2][1]);
  dp[i+2][1]=max(dp[i][1]+a[i+1]+b[i+2],dp[i+2][1]);
  dp[i+1][0]=max(dp[i][1]+a[i+1],dp[i+1][0]);
  dp[i+2][0]=max(dp[i][1]+a[i+2],dp[i+2][0]);   
}
cout << max(dp[n-1][0],dp[n-1][1]);}