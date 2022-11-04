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

LL x,y,m;

int main(){
	cin >> x >> y >> m;
	if (max(x,y)>=m){
		cout << 0 << endl;
		return 0;
	}
	if (max(x,y)<=0){
		cout << -1 << endl;
		return 0;
	}
	if (x > y) swap(x,y);
	LL ret = (y-x + (y-1)) / y;
	x+= ret * y;
	swap(x,y);
	while (y<m){
		x+=y; 
		swap(x,y);
		ret++;
	}
	cout << ret << endl;
	return 0;
}