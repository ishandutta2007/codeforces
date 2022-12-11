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
	int q;
	cin >> q;
	REP(i,0,q) {
	 ll n,dva=0,tri=0,pyat=0;
	 cin >> n;
	 while (n%2==0)
	 {
	     n=n/2;
	     dva++;
	 }
	 while (n%3==0)
	 {
	     n=n/3;
	     tri++;
	 }
	 while (n%5==0)
	 {
	     n=n/5;
	     pyat++;
	 }
	 if (n!=1)
	 cout << -1 << endl;
	 else 
	 cout << 2*tri +3*pyat + dva << endl;
	    
	    
	    
	    
	    
	    
	    
	}
	}