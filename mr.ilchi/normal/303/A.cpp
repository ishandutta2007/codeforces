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
	if (n % 2 == 0){
		cout << -1 << endl;
		return 0;
	}
	for (int i=0; i<n; i++) cout << i << ' '; cout << endl;
	for (int i=0; i<n; i++) cout << i << ' '; cout << endl;
	for (int i=0; i<n; i++) cout << 2*i%n << ' '; cout << endl;
	return 0;
}