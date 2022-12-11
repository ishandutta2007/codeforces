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
#define REP(i, a, b) for (long long i = a; i < b; i++)


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const int INF = 1e9;
int main() {
	mipletsplay;
	int t;
	cin >> t;
	REP (i,0,t)
	{
	    ll n,odin=0,dva=0,tri=0;
	    cin >>n;
	    REP (h,0,n) {
	        ll k;
	    cin  >> k;
	    if (k%3==1)
	    odin++;
	    if (k%3==2)
	    dva++;
	    if (k%3==0)
	    tri++;
	    }
	    cout << tri +(dva-min(dva,odin))/3 + (odin-min(dva,odin))/3 +min(dva,odin) << endl;
	    
	    
	    
	    
	    
	    
	} }