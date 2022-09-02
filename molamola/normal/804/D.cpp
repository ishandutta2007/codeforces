#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;

int p[100010];
vector <int> ele[100010], E[100010];
int n, m, q;

int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]); }

int dis[2][100010], D[100010], z[100010];

int far(int x,int md){
	queue <int> que; que.push(x);
	dis[md][x] = 0;
	int last = x;
	while(!que.empty()){
		int t = que.front(); que.pop();
		last = t;
		for(int e : E[t]){
			if(dis[md][e] == -1){
				dis[md][e] = dis[md][t] + 1;
				que.push(e);
			}
		}
	}
	return last;
}

vector <int> cdis[100010], csum[100010];
int dia[100010];

double calc(int x, int y){
	ll cnt = 0;
	ll rem = (ll)z[x] * z[y];
	int dx = max(dia[x], dia[y]);
	for(int e : cdis[x]){
		int t = (int)(lower_bound(all(cdis[y]), dx - 1 - e) - cdis[y].begin());
		cnt += (ll)t * dx;
		cnt += (ll)(csum[y].back() - (t == 0 ? 0 : csum[y][t-1]));
		int p = sz(csum[y]) - t;
		cnt += (ll)p * (e + 1);
	}
	return (double)cnt / rem;
}

void solve(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=1;i<=n;i++)p[i] = i, z[i] = 1;
	rep(i, m){
		int x, y; scanf("%d%d", &x, &y);
		E[x].pb(y);
		E[y].pb(x);
		x = Find(x), y = Find(y);
		p[x] = y;
		z[y] += z[x];
	}
	for(int i=1;i<=n;i++)ele[Find(i)].pb(i);
	for(int i=1;i<=n;i++)dis[1][i] = dis[0][i] = -1;
	for(int i=1;i<=n;i++)if(p[i] == i){
		int u = far(i, 0);
		for(int e : ele[i])dis[0][e] = -1;
		int v = far(u, 0);
		far(v, 1);
		dia[i] = dis[1][u];
	}
	for(int i=1;i<=n;i++){
		D[i] = max(dis[0][i], dis[1][i]);
	}
	for(int i=1;i<=n;i++){
		for(int e : ele[i]) cdis[i].pb(D[e]);
		sort(all(cdis[i]));
		csum[i].resize(sz(cdis[i]));
		for(int j=0;j<sz(cdis[i]);j++){
			csum[i][j] = (j == 0 ? 0 : csum[i][j-1]) + cdis[i][j];
		}
	}
	int BK = 300;
	
	map <pii, double> save;
	vector <int> P;
	for(int i=1;i<=n;i++)if(p[i] == i && z[i] > BK){
		P.pb(i);
	}
	rep(i, sz(P)){
		rep(j, i){
			int x = P[i], y = P[j];
			double t = calc(x, y);
			if(x > y)swap(x, y);
			save[pii(x, y)] = t;
		}
	}
	
	rep(qq, q){
		int x, y; scanf("%d%d", &x, &y);
		x = Find(x), y = Find(y);
		if(x == y){ puts("-1"); continue;}
		if(z[x] > z[y])swap(x, y);
		if(z[x] <= BK){
			printf("%.12f\n", calc(x, y));
		}
		else{
			if(x > y)swap(x, y);
			printf("%.12f\n", save[pii(x, y)]);
		}
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1; tc<=Tc; tc++){
		solve();
	}
	return 0;
}