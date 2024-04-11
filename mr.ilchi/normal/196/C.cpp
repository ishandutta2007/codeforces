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

const double eps = 1e-11;
const int maxN = 1500 + 10;

bool vis[maxN],mark[maxN];
int n;
int ans[maxN],sum[maxN];
double cost[maxN];
vector <int> adj[maxN];
pii a[maxN],f[maxN];

bool cmp (const int &A, const int &B){
	return ((ll)f[A].first * f[B].second - (ll)f[A].second * f[B].first) > 0; 
}

bool cmp1 (const int &A, const int &B){
	return a[A]<a[B];
}

void go (int x, vector <int> Q){
	
	sort(Q.begin(),Q.end(),cmp1);

	ans[Q[0]] = x; mark[x] = true;

	for (int i=1; i<(int)Q.size(); i++)
		f[Q[i]] = pii(a[Q[i]].first-a[Q[0]].first , a[Q[i]].second-a[Q[0]].second);

	sort(Q.begin()+1,Q.end(),cmp);

	int poi = 1;

	for (int i=0; i<(int)adj[x].size(); i++){
		int tmp = adj[x][i];
		if (!mark[tmp]){
			vector <int> QQ;
			while (sum[tmp]){
				QQ.push_back(Q[poi]); poi++; sum[tmp]--;
			}
			go(tmp,QQ);
		}
	}
}

void dfs (int v){
	vis[v] = true;
	sum[v] = 1;
	for (int i=0; i<(int)adj[v].size(); i++){
		int tmp = adj[v][i];
		if (!vis[tmp]){
			dfs (tmp);
			sum[v]+= sum[tmp];
		}
	}
}

int main(){

	cin >> n;
	for (int i=1; i<n; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i=1; i<=n; i++){
		cin >> a[i].first >> a[i].second;
	}
	vector <int> perm;
	for (int i=1; i<=n; i++){
		perm.push_back(i);
	}

	dfs(1);
	go(1,perm);

	for (int i=1; i<=n; i++)
		cout << ans[i] << ' ' ; cout << endl;

	return 0;
}