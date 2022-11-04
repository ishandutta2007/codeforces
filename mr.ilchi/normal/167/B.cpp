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

const int maxN = 200 + 10;

int n,l,k;
int a[maxN];
double p [maxN];
double dp[maxN][maxN][maxN];

inline double go (int id, int rem, int win){
	
	if (rem < 0)
		return 0.0;

	rem = min(rem,n-id+1);

	if (dp[id][rem][win] > -1.0)
		return dp[id][rem][win];

	if (id > n)
		return dp[id][rem][win] = (win>=l) ? 1.0 : 0.0;

	return dp[id][rem][win] = p[id]*go(id+1,rem+a[id],win+1) + (1-p[id])*go(id+1,rem,win);
}

int main(){

	cin >> n >> l >> k;

	for (int i=1; i<=n; i++) { int P; cin >> P; p[i] = P / 100.0; }
	for (int i=1; i<=n; i++) cin >> a[i];

	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++) if (a[j]>a[i]){
			swap(a[i],a[j]);
			swap(p[i],p[j]);
		}

	for (int i=0; i<maxN; i++)
		for (int j=0; j<maxN; j++)
			for (int z=0; z<maxN; z++)
				dp[i][j][z] = -2.0;

	cout << fixed << setprecision(10) << go(1,k,0) << endl;

	return 0;
}