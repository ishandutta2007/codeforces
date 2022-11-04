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

int n;
int ans[1<<20];
pii a[1<<20];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; i++){
		int temp; cin >> temp;
		a[i].first = temp;
		a[i].second= i;
	}
	sort(a, a+n);
	ans[a[0].second] = a[0].first;
	for (int i=1; i<n; i++)
		ans[a[i].second] = max(a[i].first, ans[a[i-1].second]+1);
	for (int i=0; i<n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}