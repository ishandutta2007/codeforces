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

const int MAXN = 2000+10;

int n;
double a[2*MAXN];

int getFloor (double x) { return (int)x; }
int getCeil  (double x) { return (abs(x - (int)x) > 1e-8) ? ((int)x+1) : (x); };

int main(){
	cin >> n;
	double sum = 0;
	double kaf = 0;
	int f0 = 0, f1 = 0;
	for (int i=0; i<2*n; i++){
		cin >> a[i];
		sum+= a[i];
		kaf+= getFloor(a[i]);
		if (getFloor(a[i])!=getCeil(a[i]))
			f1++;
		else
			f0++;
	}
	double mini = 1e9;
	for (int i=0; i<=min(n,f0); i++){
		if (f0-i > n)
			continue;
		mini = min(mini, abs(sum - (kaf + n-i)));
	}
	cout << fixed << setprecision(3) << mini << endl;
	return 0;
}