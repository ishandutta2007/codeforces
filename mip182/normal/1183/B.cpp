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
	int q;
	cin >>q;
	for (int h=0;h<q;h++)
	{
	    
	  ll n,k;
	  cin >>n>>k;
	  ll minix=INF,maxim=-1;
	  for (ll i=0;i<n; i++)
	  {
	    ll x;
	    cin >> x;
	    minix=min(x,minix);
	    maxim=max(x,maxim);
	  }
	  if (maxim-minix<=2*k)
	  cout <<minix+k<< endl;
	  else
	  cout << -1<<endl;
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	}}