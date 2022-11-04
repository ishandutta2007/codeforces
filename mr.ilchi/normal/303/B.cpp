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

int n,m,x,y,a,b;

int main(){
	cin >> n >> m >> x >> y >> a >> b;
	int d = __gcd(a,b); 
	a/=d;
	b/=d;
	int t = min(n/a, m/b);
	a = a * t;
	b = b * t;
	int X = max(0, x-(a+1)/2); if (X+a > n) X-= (X+a-n);
	int Y = max(0, y-(b+1)/2); if (Y+b > m) Y-= (Y+b-m);
	cout << X << ' ' << Y << ' ' << X+a << ' ' << Y+b << endl;
	return 0;
}