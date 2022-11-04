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

int n;

int main(){
	cin >> n;
	int cur = 0;
	int past=0, ans=0;
	for (int i=0; i<n; i++){
		int t,c; cin >> t >> c;
		cur = max(0, cur-(t-past));
		cur+= c;
		ans = max(ans, cur);
		past= t;
	}
	cout << past+cur << ' ' << ans << endl;
	return 0;
}