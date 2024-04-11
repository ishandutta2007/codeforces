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
typedef complex<long double> point;
typedef long double ldb;

const int MAXN = 100000;

bool mark[MAXN];
int n,edge;
int poi[MAXN];
point a[MAXN];
vector <int> ans,Q[MAXN];
vector <pii> adj[MAXN];

void dfs (int v){
	while (poi[v] < (int)adj[v].size()){
		poi[v]++;
		if (!mark[adj[v][poi[v]-1].second]){
			mark[adj[v][poi[v]-1].second] = true;
			dfs(adj[v][poi[v]-1].first);
		}
	}
	ans.push_back(v);
}

void add (int x, int y){
	edge++;
	adj[x].push_back(pii(y,edge));
	adj[y].push_back(pii(x,edge));
}

int main(){

	const point f1 = point (10*sin(54/180.0*M_PI),10*sin(36/180.0*M_PI));
	const point f2 = point (f1.real(),-f1.imag());
	const point f3 = point (-10*sin(18/180.0*M_PI),-10*sin(72/180.0*M_PI));
	const point f4 = point (-10.0,0.0);

	cin >> n;

	a[1] = point(0.0,0.0);
	a[2] = a[1] + f1;
	a[3] = a[2] + f2;
	a[4] = a[3] + f3;
	a[5] = a[4] + f4;
	add(1,3);
	add(1,4);
	add(2,4);
	add(2,5);
	add(3,5);
	for (int i=1; i<=5; i++)
		Q[1].push_back(i);
	for (int rep=2; rep<=n; rep++){
		int cur = 4 * (rep-1) + 2;
		Q[rep].push_back(cur-3);
		for (int i=0; i<4; i++)
			Q[rep].push_back(cur+i);
		a[cur] = a[cur-3] + f1;
		a[cur+1] = a[cur] + f2;
		a[cur+2] = a[cur+1] + f3;
		a[cur+3] = a[cur+2] + f4;
		add(cur-3,cur+1);
		add(cur-3,cur+2);
		add(cur,cur+2);
		add(cur,cur+3);
		add(cur+1,cur+3);
	}
	dfs(1);
	cout << fixed << setprecision(15);
	cout << 4*n+1 << endl;
	for (int i=1; i<=4*n+1; i++)
		cout << a[i].real() << ' ' << a[i].imag() << endl;
	for (int i=1; i<=n; i++){
		for (int j=0; j<5; j++)
			cout << Q[i][j] << ' ';
		cout << endl;
	}
	for (int i=0; i<(int)ans.size(); i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}