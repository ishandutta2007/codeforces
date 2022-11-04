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
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 700+10;

bool adj[MAXN][MAXN];
int n,e;
int deg [MAXN];
int same[MAXN][MAXN];

int main(){
	cin >> n >> e;
	for (int i=1; i<=e; i++){
		int e1,e2; cin >> e1 >> e2;
		adj[e1][e2] = adj[e2][e1] = true;
	}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			deg[i]+= adj[i][j];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) 
			for (int k=1; k<=n; k++) if (k!=i && k!=j && adj[i][k] && adj[j][k])
				same[i][j]++;
	ll ans = 0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) if (i!=j)
			for (int k=1; k<=n; k++) if (i!=k && j!=k && adj[j][k]){
				if (adj[i][j]) same[i][k]--;
				if (adj[i][k]) same[i][j]--;
				ans+= same[i][j] * same[i][k];
				if (adj[i][j]) same[i][k]++;
				if (adj[i][k]) same[i][j]++;
			}
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			for (int k=1; k<=n; k++) if (adj[i][j] && adj[i][k] && adj[j][k])
				ans-= deg[i]-2;
	cout << ans/10 << endl;
	return 0;
}