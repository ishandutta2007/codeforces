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
string a,b,c;
cin >>a>>b>>c;
vector <int> d;
d.pb(a[0]-48); d.pb(b[0]-48); d.pb(c[0]-48);
sort(d.begin(),d.end());
int answer=2;
if (a[1]==b[1]&& b[1]==c[1])
{
  if (d[0]==d[1] && d[1]==d[2])
  answer=min(answer,0);
  else if (d[0]==d[1]-1 && d[1]==d[2]-1)
  answer=min(answer,0);  
  else
  {
  if (d[0]==d[1] || d[2]==d[1] || d[0]==d[2] || d[0]==d[1]-1 || d[1]==d[2]-1 ||d[0]==d[1]-2 ||d[1]==d[2]-2)
  answer=min(answer,1);
  else 
 answer=min(answer,2);
  }
}
else if (a[1]==b[1]|| b[1]==c[1] || a[1]==c[1])
{
 if (a[1]==b[1]){
  vector <int> q(2);
  q[0]=a[0]-48;
  q[1]=b[0]-48;
  if (abs(q[0]-q[1])<=2)
  answer=min(answer,1);
  else
  answer=min(answer,2); }
  if (a[1]==c[1]){
  vector <int> q(2);
  q[0]=a[0]-48;
  q[1]=c[0]-48;
  if (abs(q[0]-q[1])<=2)
  answer=min(answer,1);
  else
  answer=min(answer,2); }
  if (c[1]==b[1]){
  vector <int> q(2);
  q[0]=c[0]-48;
  q[1]=b[0]-48;
  if (abs(q[0]-q[1])<=2)
  answer=min(answer,1);
  else
  answer=min(answer,2); }
  else{
      answer=min(answer,2);
  }
     
     
 }   
 else
 answer=min(answer,2);
 cout << answer;   
}