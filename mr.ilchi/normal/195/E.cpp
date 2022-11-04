/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <complex>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int maxN= 100  * 1000 + 100;
const int mod = 1000 * 1000 * 1000 + 7;

int n;
int par[maxN],cost[maxN];

int root (int x){
	if (x == par[x])
		return x;
	int t = root(par[x]);
	cost[x]+= cost[par[x]]; cost[x]%=mod;
	par [x] = t;
	return t;
}

int Union (int a, int b, int c){
	int ra = root(a);
	par [ra] = b;
	cost[ra] = (c + cost[a])%mod;
	return cost[ra];
}

int main(){

	cin >> n;

	int ans = 0;

	for (int i=1; i<=n; i++){
		par[i] = i;
		int k; cin >> k;
		for (int j=1; j<=k; j++){
			int v,x; 
			cin >> v >> x; 
			ans = (ans + Union(v,i,x))%mod;
		}
	}

	ans%=mod; ans+=mod; ans%=mod;

	cout << ans << endl;

	return 0;
}