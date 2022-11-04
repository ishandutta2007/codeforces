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

const int MAXN = 150000+10;

int len,n,h;
int a[MAXN],b[MAXN];
int dp[1<<20],all[1<<20];

inline void go (int root, int lo, int hi, int s, int e, int key){
	if (hi<s || e<lo)
		return;
	if (s<=lo && hi<=e){
		all[root]+= key;
		dp [root]+= key;
		return;
	}
	int mid = (lo+hi)/2;
	go(root*2,lo,mid,s,e,key);
	go(root*2+1,mid+1,hi,s,e,key);
	dp[root] = min(dp[root*2],dp[root*2+1]) + all[root];
}

inline void build (int root, int lo, int hi){
	if (lo == hi){
		dp[root] = -lo;
		return;
	}
	int mid = (lo+hi)/2;
	build(root*2,lo,mid);
	build(root*2+1,mid+1,hi);
	dp[root] = -hi;
}

int main(){
	cin >> n >> len >> h;
	for (int i=0; i<len; i++) cin >> b[i];
	for (int i=0; i<n; i++) cin >> a[i];
	sort(b,b+len);
	int ret = 0;
	build(1,0,len-1);
	for (int i=0; i<n; i++){
		int poi = lower_bound(b, b+len, h-a[i]) - b;
		go(1, 0, len-1, poi, len-1, 1);
		if (len<=i+1){
			ret+= (dp[1] > 0);
			poi = lower_bound(b, b+len, h-a[i-len+1]) - b;
			go(1, 0, len-1, poi, len-1, -1);
		}
	}
	cout << ret << endl;
	return 0;
}