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

int n,m;
LL h[MAXN],p[MAXN];

inline bool check (LL cur, LL lo, LL hi, LL mid){
	if (cur <= lo)
		return (hi-cur) <= mid;
	if (cur >= hi)
		return (cur-lo) <= mid;
	return (hi-lo + min(cur-lo, hi-cur)) <= mid;
}

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> h[i];
	for (int i=0; i<m; i++) cin >> p[i];
	LL lo = 0, hi = (1LL<<40), ans = 0;
	while (lo <= hi){
		LL mid = (lo + hi) / 2;
		int poi = 0;
		for (int i=0; i<n && poi<m; i++){
			int temp = poi;
			while (poi<m && check(h[i], p[temp], p[poi], mid))
				poi++;
		}
		if (poi == m){
			ans = mid;
			hi = mid-1;
		}else
			lo = mid+1;
	}
	cout << ans << endl;
	return 0;
}