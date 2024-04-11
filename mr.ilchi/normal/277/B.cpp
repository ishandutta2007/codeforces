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

int n,m;

int main(){
	cin >> n >> m;
	if (m==3 && n>4){
		cout << -1 << endl;
		return 0;
	}
	for (int i=0; i<m; i++)
		cout << i << ' ' << (i * (i+1))/2 << endl;
	for (int i=m; i<n; i++)
		cout << 10000000 + i << ' ' << ((2*m-i) * (2*m-i-1))/2 << endl;
	return 0;
}