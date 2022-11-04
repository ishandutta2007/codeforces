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

bool mark[4000000+10];
int n,m;

int get (int x, int y){
	if (x<1 || x>n || y<1 || y>m)
		return 0;
	if (x==1)
		return y;
	if (x==n)
		return m + 2*n-4 + y;
	return m + 2 * (x-1) - (y==1);
}

void dfs (int v){
	if (mark[v]) return;
	mark[v] = true;
	int x = (v<=m) ? (1) : (v<=m+2*n-4) ? ((v-m+1)/2+1) : (n);
	int y = (v<=m) ? (v) : (v<=m+2*n-4) ? ((v-m+1)%2*(m-1)+1) : (v-m-2*n+4);
	dfs(get(n,y+n-x)); dfs(get(n,y-n+x));
	dfs(get(1,y+x-1)); dfs(get(1,y-x+1));
	dfs(get(x+m-y,m)); dfs(get(x-m+y,m));
	dfs(get(x+y-1,1)); dfs(get(x-y+1,1));
}

int main(){
	cin >> n >> m;
	int ans = 0;
	mark[0]=true;
	for (int i=1; i<=2*(n+m-2); i++) if (!mark[i]) ans++ , dfs(i);
	cout << ans << endl;
	return 0;
}