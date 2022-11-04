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

const int MAXN = 500+10;
const int inf = 1000000000;

int n;
int x[MAXN];
int adj[MAXN][MAXN];
int dis[MAXN][MAXN];
LL ans[MAXN];

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> adj[i][j];
	for (int i=0; i<n; i++){
		cin >> x[i];
		x[i]--;
	}
	reverse(x, x+n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) if (i!=j)
			dis[i][j] = inf;
	for (int i=0; i<n; i++){
		for (int k=0; k<i; k++){
			dis[x[i]][x[k]] = adj[x[i]][x[k]];
			dis[x[k]][x[i]] = adj[x[k]][x[i]];
		}
		for (int k=0; k<i; k++)
			for (int t=0; t<i; t++){
				dis[x[i]][x[t]] = min(dis[x[i]][x[t]], dis[x[i]][x[k]] + dis[x[k]][x[t]]);
				dis[x[t]][x[i]] = min(dis[x[t]][x[i]], dis[x[t]][x[k]] + dis[x[k]][x[i]]);
			}
		for (int k=0; k<i; k++)
			for (int t=0; t<i; t++)
				dis[x[k]][x[t]] = min(dis[x[k]][x[t]], dis[x[k]][x[i]] + dis[x[i]][x[t]]);
		for (int ii=0; ii<=i; ii++)
			for (int jj=ii+1; jj<=i; jj++)
				ans[n-i-1]+= dis[x[ii]][x[jj]] + dis[x[jj]][x[ii]];
	}
	for (int i=0; i<n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}