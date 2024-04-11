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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

const double pi = 3.141592653589;
const double eps = 1e-8;

int n,r,R;

int main(){
	
	cin >> n >> R >> r;

	if (r > R){
		cout << "NO" << endl;
		return 0;
	}

	if (n==1){
		cout << "YES" << endl;
		return 0;
	}

	if (2*r > R){
		cout << "NO" << endl;
		return 0;
	}

	if (2*r==R){
		if (n==2){
			cout << "YES" << endl;
			return 0;
		}
		cout << "NO" << endl;
		return 0;
	}

	int a = R-r;
	int b = R-r;
	int c = 2*r;

	double f = asin(((double)r)/(double)a) * 2;

	if (f * n < 2*pi + eps){
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;

	return 0;
}