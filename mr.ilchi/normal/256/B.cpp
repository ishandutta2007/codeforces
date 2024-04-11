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

LL n,x,y,c;

LL solve (LL t, LL n, LL m){
	if (t < 0) 
		return 0;
	if (n < 1 || m < 1)
		return 0;
	if (t + 1 <= n){
		LL end = t+1;
		LL first = max(1LL,t+1-m+1);
		return (end-first+1) * (first+end) / 2;
	}
	LL up = t+1 - n;
	return min(m,up+1) * n + solve(t-up-1, n, m-up-1);
}

int main(){
	cin >> n >> x >> y >> c;
	LL lo=0, hi=2*n, ans=-1;
	while (lo<=hi){
		LL mid = ((LL)lo + hi) / 2;
		LL cur = 1 + min(mid, x-1) + min(mid, n-x) + min(mid, y-1) + min(mid, n-y);
		cur+= solve(mid-2, x-1, y-1);
		cur+= solve(mid-2, x-1, n-y);
		cur+= solve(mid-2, n-x, y-1);
		cur+= solve(mid-2, n-x, n-y);
		if (cur >= c){
			ans = mid;
			hi = mid-1;
		}
		else
			lo = mid+1;
	}
	cout << ans << endl;
	return 0;
}