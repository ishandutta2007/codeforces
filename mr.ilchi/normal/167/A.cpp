/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int n;
double a,d;

double go (double t, double v){
	double tTov = v / a;
	if (a*tTov*tTov/2.0 < d)
		return t + tTov + (d - a*tTov*tTov/2.0) / v;
	return t + sqrt(2.0*d/a);
}

int main(){

	cin >> n >> a >> d;

	double past = 0.0;
	
	cout << fixed << setprecision(10);

	for (int i=1; i<=n; i++){
		double t,v; cin >> t >> v;
		past = max(past,go(t,v));
		cout << past << endl;
	}
		
	return 0;
}