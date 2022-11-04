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

ll n,t,b,k;

int main(){
	
	cin >> k >> b >> n >> t;

	if (k == 1){
		for (int i=0; i<=n; i++){
			if (t + i * b >= 1 + n * b){
				cout << i << endl;
				return 0;
			}
		}
	}

	if (t==1){
		cout << n << endl;
		return 0;
	}

	int less = 0;

	while (less<=n){
		less++;
		ll tmp = 1;
		for (int i=1; i<=less; i++)
			tmp*=k;
		tmp--;
		if ((tmp>(k-1)*(t-1)) || (tmp * (b+k-1) > (k-1)*(t-1)))
			break;
	}

	cout << n-less+1 << endl;

	return 0;
}