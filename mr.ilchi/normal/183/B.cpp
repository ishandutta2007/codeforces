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

const int maxN = 1000 * 1000 + 10;;

int n,m;
int x[maxN],y[maxN],ans[maxN];

int main(){

	cin >> n >> m;

	for (int i=1; i<=m; i++){
		cin >> x[i] >> y[i];
	}

	for (int i=1; i<=m; i++){
		
		for (int j=i+1; j<=m; j++) if (y[i]!=y[j]){

			int dx = (x[i]-x[j]);
			int dy = (y[i]-y[j]);

			if (((ll)y[i] * (ll)dx) % dy != 0)
				continue;

			ll X = x[i] - ((ll)y[i] * dx / dy);

			if (X>n || X<1) continue;

			int cnt = 2;

			for (int z=j+1; z<=m; z++) if (y[i]!=y[z]){
				int d2x = (x[i]-x[z]);
				int d2y = (y[i]-y[z]);
				if ((ll)dx * (ll)d2y == (ll)d2x * (ll)dy)
					cnt++; 
			}

			ans[X] = max(ans[X],cnt);
		}
	}

	ll sum = 0;

	for (int i=1; i<=n; i++) sum+= max(1,ans[i]);

	cout << sum << endl;

	return 0;
}