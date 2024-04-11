/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100000+10;
const int mod  = 1000000009;

bool rem[MAXN];
int n,k,a,b,c,d,que;
int x[MAXN],y[MAXN],L[MAXN],R[MAXN];
int dp[MAXN],lo[MAXN],hi[MAXN];

bool cmp (const int &A, const int &B) { return y[A]>y[B]; }

void build (vector <int> perm){
	int root = perm[0];
	lo [root] = hi[root] = x[root];
	rem[root] = true;
	dp [root] = 0;
	vector <int> lef,rig;
	for (int i=1; i<(int)perm.size(); i++){ 
		if (x[root]>x[perm[i]]) 
			lef.push_back(perm[i]);
		else
			rig.push_back(perm[i]);
	}
	if (!lef.empty()){
		L[root] = lef[0];
		build(lef);
		lo[root] = min(lo[root] , lo[lef[0]]);
		dp[root]+= dp[lef[0]];
		if (rem[root] && rem[lef[0]]){
			rem[root] = 0; dp[root]++;
		}
	}
	if (!rig.empty()){
		R[root] = rig[0];
		build(rig);
		hi[root] = max(hi[root] , hi[rig[0]]);
		dp[root]+= dp[rig[0]];
		if (rem[root] && rem[rig[0]]){
			rem[root] = 0; dp[root]++;
		}
	}
}

pii go (int v, int minx, int maxx){
	if (v==0 || hi[v]<minx || maxx<lo[v])
		return pii(0,0);
	if (minx<=lo[v] && hi[v]<=maxx)
		return pii(dp[v],rem[v]);
	if (x[v]<minx)
		return go(R[v],minx,maxx);
	if (x[v]>maxx)
		return go(L[v],minx,maxx);
	pii f1 = go(L[v],minx,maxx);
	pii f2 = go(R[v],minx,maxx);
	return pii(f1.first+f2.first+(f1.second||f2.second),!(f1.second||f2.second));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	vector <int> perm;
	for (int i=1; i<=k; i++){
		cin >> x[i] >> y[i];
		perm.push_back(i);
	}
	cin >> a >> b  >> c >> d;
	for (int i=k+1; i<=n; i++){
		x[i] = ((ll)a * x[i-1] + b) % mod;
		y[i] = ((ll)c * y[i-1] + d) % mod;
		perm.push_back(i);
	}
	sort(perm.begin(),perm.end(),cmp);
	build(perm);
	cin >> que;
	for (int i=1; i<=que; i++){
		int minx,maxx; cin >> minx >> maxx;
		cout << go(perm[0],minx,maxx).first << endl;
	}
	return 0;
}