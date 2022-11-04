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
int q[MAXN],a[MAXN];

int main(){
	cin >> m;
	for (int i=0; i<m; i++) cin >> q[i];
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a,a+n);
	int t = *min_element(q, q+m);
	int sum = 0;
	for (int i=0; i<n; i++)
		sum+= a[i];
	for (int i=n-1-t; i>=0; i-=	(t+1)){
		sum-= a[i];
		i--;
		if (i>=0) sum-=a[i];
	}
	cout << sum << endl;
	return 0;
}