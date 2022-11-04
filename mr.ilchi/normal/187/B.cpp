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

const int maxN = 60 + 10;

int n,m,que;
int dis[maxN][maxN][maxN],ans[maxN][maxN][maxN];

int main(){
	
	scanf("%d%d%d" , &n, &m, &que);

	for (int rep=1; rep<=m; rep++){
		
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				scanf ("%d" , &dis[rep][i][j]);

		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				for (int k=1; k<=n; k++)
					dis[rep][j][k] = min(dis[rep][j][k] , dis[rep][j][i] + dis[rep][i][k]);
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++){
			ans[i][j][0] = dis[1][i][j];
			for (int z=1; z<=m; z++)
				ans[i][j][0] = min(ans[i][j][0] , dis[z][i][j]);
		}

	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++){
				ans[i][j][k] = ans[i][j][k-1];
				for (int z=1; z<=n; z++)
					ans[i][j][k] = min(ans[i][j][k] , ans[i][z][0] + ans[z][j][k-1]);
			}

	for (int o=1; o<=que; o++){
		int s,t,k; scanf("%d%d%d" , &s, &t, &k);
		printf("%d\n" , ans[s][t][min(n,k)]);
	}

	return 0;
}