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
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

vector <int> E[100010], F[100010];
int ans[100010];
vector <int> A[100010];
int n, m;

struct str{
	str(){}
	str(int x){idx = x;}
	vector <int> v;
	int idx;
	void out(){
		printf("idx : %d\n", idx);
		for(int e : v)printf("%d ", e); puts("");
	}
	void DoSort(){
		sort(all(v)); reverse(all(v));
	}
	bool operator<(const str &rhs)const{
		for(int i=0;i<sz(v) && i<sz(rhs.v);i++){
			if(v[i] != rhs.v[i])return v[i] < rhs.v[i];
		}
		return sz(v) < sz(rhs.v);
	}
}V[100010];
int cv;

int Do(int l, int r, vector <int> &u){
	auto it = lower_bound(all(A[l]), r);
	if(it != A[l].end() && *it == r && sz(u) > 0){
		vector <int> emp;
		++cv; V[cv] = str(cv);
		V[cv].v = u;
		V[cv].v.pb(l);
		V[cv].v.pb(r);
		int save = cv;
		int a = Do(l, r, emp);
		F[V[a].idx].pb(V[save].idx);
		return save;
	}
	int t = (int)(upper_bound(all(A[r]), l) - A[r].begin());
	if(t != sz(A[r]) && A[r][t] < r){
		vector <int> emp;
		u.pb(r);
		int a = Do(l, A[r][t], u);
		u.pop_back();
		int b = Do(A[r][t], r, emp);
		F[V[a].idx].pb(V[b].idx);
		return a;
	}
	else{
		auto it = lower_bound(all(A[l]), r);
		if(it != A[l].begin()){
			--it;
			if(*(it) > l){
				vector <int> emp;
				int t = *it;
				int a = Do(l, t, emp);
				u.pb(l);
				int b = Do(t, r, u);
				u.pop_back();
				F[V[a].idx].pb(V[b].idx);
				return b;
			}
		}
	}
	if(l == r){
		++cv; V[cv] = str(cv);
		V[cv].v = u;
		for(int i=l;i<=r;i++)V[cv].v.pb(i);
		return cv;
	}
	else{
		u.pb(l);
		return Do(l+1, r, u);
	}
}

int rev[100010];
int down[100010];
int cut[100010];

void dfs(int x, int fa){
	down[x] = 1;
	for(int e : E[x])if(e != fa && cut[e] == 0){
		dfs(e, x);
		down[x] += down[e];
	}
}

int cen(int x){
	int h = down[x] / 2;
	while(1){
		int ch = 0;
		for(int e : E[x])if(cut[e] == 0){
			if(down[x] > down[e] && down[e] > h){
				x = e;
				ch = 1; break;
			}
		}
		if(ch == 0)break;
	}
	return x;
}

void Do(int x, int col){
	dfs(x, -1);
	x = cen(x);
	ans[x] = col;
	cut[x] = 1;
	for(int e : E[x])if(cut[e] == 0){
		Do(e, col + 1);
	}
}

void solve(){
	scanf("%d%d", &n, &m);
	rep(i, m){
		int x, y; scanf("%d%d", &x, &y);
		A[x].pb(y);
		A[y].pb(x);
	}
	for(int i=1;i<=n;i++)sort(all(A[i]));
	vector <int> emp;
	Do(1, n, emp);
	for(int i=1;i<=cv;i++){
		V[i].DoSort();
	}
	sort(V+1, V+1+cv);
	for(int i=1;i<=cv;i++)rev[V[i].idx] = i;
	for(int i=1;i<=cv;i++)for(int e : F[i]){
		int x = rev[i], y = rev[e];
		E[x].pb(y); E[y].pb(x);
	}
//	for(int i=1;i<=cv;i++)V[i].out(); for(int i=1;i<=cv;i++)for(int e : E[i])printf("%d %d\n", i, e);
	Do(1, 1);
	for(int i=1;i<=cv;i++)printf("%d ", ans[i]);
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}