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
	ll x,y,z,kek=0;
	cin >> x>>y>>z;
	ll answer=(x+y)/z;
	cout << answer << " ";
	ll answer1= z -x%z;
	ll answer2=z - y%z;
	
	if (answer1<=y%z)
	{
	    kek=answer1;
	}
	if (answer2<=x%z)
	{
	    if (kek==0)
	    kek=answer2;
	    else
	    kek=min(answer1,answer2);
	}
	cout << kek;
	
	
	
	
	
}