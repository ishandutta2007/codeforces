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
typedef pair<int,int> pii;
typedef complex<double> point;

int n,m;
pii a[1<<20];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=0; i<m; i++)
		cin >> a[i].second >> a[i].first;
	sort(a, a+m, greater<pii>());
	LL ans = 0;
	LL cur = 0;
	for (int i=0; i<m; i++){
		cur+= a[i].first;
		LL need = (i+1LL) * i / 2LL;
		if (i%2 == 1)
			need+= (i-1)/2;
		if (need < n)
			ans = cur;
	}
	cout << ans << endl;
	return 0;
}