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

int n,m,x,y,xx,yy;

int main(){
	
	cin >> n >> m >> x >> y >> xx >> yy;

	int dx = labs(x-xx);
	int dy = labs(y-yy);

	if (dx>dy) dx--; else dy--;

	if (max(dx,dy)<=3 && min(dx,dy)!=3)
		cout << "First" << endl;
	else
		cout << "Second" << endl;
	return 0;
}