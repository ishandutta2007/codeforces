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
string s;
cin >> s;
vector <ll> a;
vector  <ll> pref;
pref.pb(0);
ll chet=0,sum=0,kek=1;
ll u=0;
while (s[u]=='o')
u++;
char f='v';
for (ll i=u;i<s.size();i++)
{
 if (s[i]==f)   
 chet++;
 else
 {
 if (f=='v'){
 ll k=pref[pref.size()-1];
 pref.pb(k+chet-1);
 a.pb(chet-1);
 f=s[i];
 chet=1;
 }
 else
 {
 a.pb(chet);
 ll k=pref[pref.size()-1];
 pref.pb(k);
 f=s[i];
 chet=1;
     
 }
 }
}
  if (f=='v') {  
  a.pb(chet-1);
  ll k=pref[pref.size()-1];
  pref.pb(k+chet-1);
  }
  ll answer=0;
  for (int i=1;i<a.size();i=i+2)
  {
   answer+=pref[i+1]*(pref[pref.size()-1]-pref[i+1])*a[i];
      
      
      
      
  }
  cout << answer;}