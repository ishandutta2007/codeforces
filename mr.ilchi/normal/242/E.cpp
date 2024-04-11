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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

const int MAXN = 100000+10;
const int MAXT = (1<<18) + 10;

int n,que;
int a[MAXN],XOR[MAXT];
vector <int> dp[MAXT];

vector <int> get (int root, int start, int end, int lo, int hi){
	if (end<lo || hi<start)
		return vector <int> (20,0);
	if (lo<=start && end<=hi)
		return dp[root];
	int mid = (start + end) / 2;
	vector <int> f1 = get((root<<1), start, mid, lo, hi);
	vector <int> f2 = get((root<<1)+1, mid+1, end, lo, hi);
	vector <int> ret(20,0);
	int intersect = min(end,hi) - max(start,lo) + 1;
	for (int i=0; i<20; i++){
		ret[i] = f1[i] + f2[i];
		if (XOR[root] & (1<<i))
			ret[i] = intersect - ret[i];
	}
	return ret;
}

void go (int root, int start, int end, int lo, int hi, int cost){
	if (end<lo || hi<start)
		return;
	if (lo<=start && end<=hi){
		XOR[root] = XOR[root] ^ cost;
		for (int i=0; i<20; i++) if (cost & (1<<i))
			dp[root][i] = (end-start+1) - dp[root][i];
		return;
	}
	int mid = (start + end) / 2;
	go((root<<1), start, mid, lo, hi, cost);
	go((root<<1)+1, mid+1, end, lo, hi, cost);
	int L = (root<<1);
	int R = (root<<1) + 1;
	for (int i=0; i<20; i++){
		dp[root][i] = dp[L][i] + dp[R][i];
		if (XOR[root] & (1<<i))
			dp[root][i] = (end-start+1) - dp[root][i];
	}
}

int main(){
	cin >> n;
	for (int i=0; i<MAXT; i++)
		dp[i] = vector <int> (20,0);
	for (int i=1; i<=n; i++){
		cin >> a[i];
		go(1,1,n,i,i,a[i]);
	}
	cin >> que;
	for (int o=0; o<que; o++){
		int type; cin >> type;
		if (type == 1){
			int lo,hi; cin >> lo >> hi;
			vector <int> ret = get(1,1,n,lo,hi);
			LL ans = 0;
			for (int i=0; i<20; i++)
				ans= ans + (1LL<<i) * ret[i];
			cout << ans << endl;
		}
		else{
			int lo,hi,x; cin >> lo >> hi >> x;
			go(1,1,n,lo,hi,x);
		}
	}
	return 0;
}