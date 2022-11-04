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

const int maxN = 1000 + 10;

int n,m;
ll R[maxN],C[maxN];
ll cost[maxN][maxN],sum1[maxN][maxN],row[maxN][maxN],col[maxN][maxN];

int main(){
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			cin >> cost[i][j];
			sum1[i][j] = sum1[i][j-1] + sum1[i-1][j] - sum1[i-1][j-1] + cost[i][j];
			row [i][j] = row [i][j-1] + row [i-1][j] - row [i-1][j-1] + cost[i][j] * (4 * i - 2);
			col [i][j] = col [i][j-1] + col [i-1][j] - col [i-1][j-1] + cost[i][j] * (4 * j - 2);
		}
	for (ll i=0; i<=n; i++)
		R[i] = 16ll * i * i * sum1[n][m] - 8ll * i * row[n][m];
	for (ll j=0; j<=m; j++)
		C[j] = 16ll * j * j * sum1[n][m] - 8ll * j * col[n][m];

	ll dis = (1ll<<60);

	int X=0;
	int Y=0;

	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++) if (R[i] + C[j] < dis){
			dis = R[i] + C[j];
			X = i;
			Y = j;
		}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			ll x = 4 * i - 2; 
			ll y = 4 * j - 2; 
			dis+= (x * x + y * y) * cost[i][j];
		}

	cout << dis << endl;
	cout << X << ' ' << Y << endl;

	return 0;
}