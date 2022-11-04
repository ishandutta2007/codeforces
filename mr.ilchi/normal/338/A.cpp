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

const int mod = 1000000009;

LL n,m,k;

inline LL POWER (LL base, LL p){
	LL ret=1,cur=base;
	while (p){
		if (p & 1)
			ret = ret * cur % mod;
		p>>=1;
		cur = cur * cur % mod;
	}
	return ret;
}

int main(){
	cin >> n >> m >> k;
	LL lo = 0, hi = n/k, ans = -1;
	while (lo<=hi){
		LL mid = (lo + hi) / 2;
		if (m <= mid * k + (n/k-mid)*(k-1) + n%k){
			ans = mid;
			hi = mid-1;
		}else
			lo = mid+1;
	}
	cout << ((k * (POWER(2,ans+1)-2)%mod + m - ans * k)%mod + mod) % mod << endl;
	return 0;
}