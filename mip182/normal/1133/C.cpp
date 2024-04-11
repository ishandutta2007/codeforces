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
int n;
cin>>n;
vector <int> a(n);
for (int i=0;i<n;i++)
cin>>a[i];
int j=0;
ll answer=-1;
ll chet=0;
sort(a.begin(),a.end());
for (int i=0;i<n;i++)
{
  while (j<=n-1 &&a[i]+5>=a[j])
  {
  chet++;
  j++;
  }
  answer=max(answer,chet);
  chet--;  
    
}
cout<<answer;
}