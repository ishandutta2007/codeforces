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

int n,sum;
int x[10],y[10],xx[10],yy[10];

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> x[i] >> y[i] >> xx[i] >> yy[i];
		sum+= (xx[i] - x[i]) * (yy[i] - y[i]);
	}
	int minx = *min_element(x, x+n);
	int maxx = *max_element(xx, xx+n);
	int miny = *min_element(y, y+n);
	int maxy = *max_element(yy, yy+n);
	if (((maxx-minx) == (maxy-miny)) && ((maxx-minx)*(maxy-miny) == sum))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}