//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 100 * 1000 + 100;

int par[N]; 

int dfind(int u) { 
	return par[u] < 0 ? u : par[u] = dfind(par[u]); 
}

bool merge(int u, int v) { 
	u = dfind(u); 
	v = dfind(v); 

	if( u == v ) return false;

	if( par[u] > par[v] ) swap(u, v); 

	par[u] += par[v]; 
	par[v] = u; 

	return true; 
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); 

	memset(par, -1, sizeof par); 

	int n, k;
	cin >> n >> k;

	int ans = 0; 
	for(int i = 0; i < k; i++) { 
		int u, v;
		cin >> u >> v; 
		u--; v--; 
		ans += merge(u, v); 
	}

	cout << k- ans << endl;

    return 0;
}