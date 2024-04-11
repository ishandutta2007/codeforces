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

const int maxN = 30 + 3;

int n,u,r;
ll ans;
int a[maxN],b[maxN],p[maxN],k[maxN],tt[maxN];

ll getScore (){
	ll ret = 0;
	for (int i=1; i<=n; i++) ret+= (ll)a[i] * k[i];
	return ret;
}

void XOR (){
	for (int i=1; i<=n; i++) a[i] ^= b[i];
}

void perm(){
	
	for (int i=1; i<=n; i++) tt[i] = a[p[i]] + r;
	for (int i=1; i<=n; i++) a [i] = tt[i];
}

void go (int move, bool f){

	if (move%2 == 0){
		ans = max(ans,getScore());
	}

	if (move==0)
		return;

	vector <int> test(maxN);

	for (int i=1; i<=n; i++)
		test[i] = a[i];

	if (!f){
		XOR(); go(move-1,1);
		for (int i=1; i<=n; i++)
			a[i] = test[i];
	}

	perm(); go(move-1,0);
	for (int i=1; i<=n; i++)
		a[i] = test[i];
}

int main(){

	ans = -(1ll<<60);

	cin >> n >> u >> r;

	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	for (int i=1; i<=n; i++) cin >> k[i];
	for (int i=1; i<=n; i++) cin >> p[i];	

	go(u,0);

	cout << ans << endl;

	return 0;
}