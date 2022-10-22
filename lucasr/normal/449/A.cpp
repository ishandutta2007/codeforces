#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
 
using namespace std;
 
#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

int main() {
	long long n, m, k;
	cin>>n>>m>>k;
	k+=2;
	if (k > n + m) {
		cout<<-1<<endl;
	} else {
		long long ans = 1;
		for (long long r = 1; r <= n/r; r++) {
			long long inv = n / r;
			long long resto = max(1ll, k - r);
			ans = max(ans, inv * (m / resto));
			resto = max(1ll, k - inv);
			ans = max(ans, r * (m / resto));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}