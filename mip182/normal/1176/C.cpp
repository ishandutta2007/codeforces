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
	ll n,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0;
	cin >>n;
	vector <ll> v(n);
	REP(m,0,n)
	cin >> v[m];
	REP(i,0,n)
	{ if (v[i]==4)
	  a1++;
	  else if (v[i]==8 && a1>a2)
	  a2++;
	  else if (v[i]==15 && a2>a3)
	  a3++;
	  else if (v[i]==16 && a3>a4)
	  a4++;
	  else if (v[i]==23 && a4>a5)
	  a5++;
	  else if (v[i]==42 && a5>a6)
	  a6++;
	}
    cout << n- 6*a6;
}