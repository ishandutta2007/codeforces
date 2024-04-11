#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())
typedef long long lld;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

void solve()
{
	int N, M, K; scanf("%d%d%d", &N, &M, &K);
	vector<vector<int>> con(N+1);
	vector<int> deg(N+1);
	for (int i=1;i<=M;i++){
		int a, b; scanf("%d%d", &a, &b);
		con[a].push_back(b); con[b].push_back(a);
		deg[a]++; deg[b]++;
	}
	if ((lld)K*(K-1) > M+M){ puts("-1"); return; }
	set<pair<int, int>> deg_set;
	for (int i=1;i<=N;i++) deg_set.insert({deg[i], i});

	vector<int> order(N+1), seq;
	while (!deg_set.empty()){
		static int ocnt = 0;
		auto [d, u] = *deg_set.begin();
		order[u] = ++ocnt; seq.push_back(u);
		if (d >= K){
			vector<int> grp;
			for (int i=1;i<=N;i++) if (deg[i] != -1) grp.push_back(i);
			printf("1 %d\n", sz(grp));
			for (int v: grp) printf("%d ", v); puts("");
			return;
		}
		deg_set.erase({d, u}); deg[u] = -1;
		for (int v: con[u]) if (deg[v] != -1){
			deg_set.erase({deg[v], v});
			deg[v]--;
			deg_set.insert({deg[v], v});
		}
	}

	vector<vector<pair<int, int>>> check_list(N+1);
	vector<int> color(N+1);
	vector<bool> found(N+1);
	for (int u: seq){
		static int ccnt = 0; ccnt++;
		vector<int> arr;
		for (int v: con[u]){
			if (order[u] < order[v]) arr.push_back(v);
			color[v] = ccnt;
		}
		for (auto [v, p]: check_list[u]) if (color[v] != ccnt) found[p] = 0;
		if (sz(arr) == K-1){
			found[u] = 1;
			for (int i=0;i<K-1;i++) for (int j=0;j<K-1;j++) if (i != j && order[arr[i]] > order[arr[j]])
				check_list[arr[i]].push_back({arr[j], u});
		}
	}

	for (int i=1;i<=N;i++) if (found[i]){
		printf("2\n%d", i);
		for (int j: con[i]) if (order[j] > order[i]) printf(" %d", j);
		puts("");
		return;
	}
	puts("-1");
}

int main()
{
	int T;
	for (scanf("%d", &T);T--;) solve();
}