#include <bits/stdc++.h>
typedef long long ll;

#define PB push_back
#define EB emplace_back 
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
    ll n,chet,kek=0;
    cin >> n;
    vector <double> a(n);
    for (ll i=0;i<n;i++)
    {
    cin >> a[i];
    if (a[i]-floor(a[i])==0)
    chet++;
    kek +=floor(a[i]);}
    for (ll j=0;j<n;j++)
    {
      if (a[j]-floor(a[j])==0)
      cout << a[j] << endl;
      else {
      if (kek!=0) {
      ll s=ceil(a[j]);
      if (s==-0)
      s=0;
      cout << s<<endl;
      kek++;
      }
      else
      cout << floor(a[j])<< endl;
        
          
          
      }
        
        
        
        
        
    }
    
}