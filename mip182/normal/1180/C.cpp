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
	ll n,q;
	cin >> n>>q;
	deque <ll> a;
	vector <pair<ll,ll>> h;
	for (ll i=0;i<n;i++)
	{ ll k;
	cin >>k;
	a.PB(k);
	}
	vector <ll> b(a.begin(),a.end());
	sort(b.begin(),b.end());
	ll maxim=b[b.size()-1];
	while(a[0]!=maxim)
	{
	 ll x=a[0], y=a[1];
	 if (a[0]>a[1])
	 {
	   a.pop_front();
	   a.pop_front();
	   a.PB(y);
	   a.push_front(x);
	   h.PB({x,y});  
	 }
	 else {
	   a.pop_front();
	   a.pop_front();
	   a.PB(x);
	   a.push_front(y);
	   h.PB({x,y});   
	 }
	}
	
	
	
	
	for (ll j=0;j<q;j++)
	{
	 ll m;
	 cin >>m;
	 if (m<=h.size())
	 cout << h[m-1].first << " "<<  h[m-1].second<< endl;
	 else
	 cout << maxim << " "<<  a[(m-h.size()-1)%(n-1)+1]<< endl;
	 
	    
	    
	    
	    
	    
	    
	}
	}