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

const int maxN = 20 * 1000 + 10;

int n;
int a[maxN],f[maxN];

inline int go (int dis){
	
	if (n/dis < 3)
		return -(1<<30);

	for (int i=0; i<n; i++){
		int rem = i%dis;
		f[rem] = (rem==i) ? (a[i]) : (f[rem]+a[i]);
	}
	
	return *max_element(f,f+dis);
}

int main(){
	
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	int ans = -(1<<30);

	for (int i=1; i*i<=n; i++) if (n%i==0){
		ans = max(ans,go(i));
		ans = max(ans,go(n/i));
	}

	cout << ans << endl;

	return 0;
}