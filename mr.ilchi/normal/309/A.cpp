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

LL n,l,t;
LL a[1<<21];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> l >> t;
	for (int i=0; i<n; i++){
		cin >> a[i];
		a[i+n] = a[i] + l;
	}
	t<<=1;
	LL rem = t%l;
	LL ret = 0.0;
	for (int i=0; i<n; i++){
		int len = upper_bound(a, a+2*n, a[i]+rem) - a - i - 1;
		ret+= (LL)t/l * (n-1-len) + (t/l+1LL) * len; 
	}
	cout << fixed << setprecision(10) << (long double)ret/4.0 << endl;
	return 0;
}