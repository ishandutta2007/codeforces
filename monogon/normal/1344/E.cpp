
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

const int N = 1e5 + 5, M = 1e5 + 5;

// tree1[i] => store index of most recent train with destination i.
// tree2[i] => store top node of path leading to i.
// lazy2[i] => if value = 0, do nothing. Otherwise, replace min value on range with new value.

int tree1[4 * N], tree2[4 * N], lazy2[4 * N];

int query1(int i, int l, int r, int L, int R) {
	if(r < L || R < l) return 0;
	if(L <= l && r <= R) return tree1[i];
	int m = (l + r) / 2;
	return max(query1(2 * i + 1, l, m, L, R), query1(2 * i + 2, m + 1, r, L, R));
}
void upd1(int i, int l, int r, int k, int x) {
	if(l == r) {
		tree1[i] = x;
		return;
	}
	int m = (l + r) / 2;
	if(k <= m) upd1(2 * i + 1, l, m, k, x);
	else upd1(2 * i + 2, m + 1, r, k, x);
	tree1[i] = max(tree1[2 * i + 1], tree1[2 * i + 2]);
}

int minval2(int i) {
	return lazy2[i] == 0 ? tree2[i] : lazy2[i];
}
void prop2(int i, int l, int r) {
	if(lazy2[i] == 0) return;
	if(l < r) {
		if(minval2(2 * i + 1) == tree2[i]) lazy2[2 * i + 1] = lazy2[i];
		if(minval2(2 * i + 2) == tree2[i]) lazy2[2 * i + 2] = lazy2[i];
	}
	tree2[i] = lazy2[i];
	lazy2[i] = 0;
}
int query2(int i, int l, int r, int k) {
	prop2(i, l, r);
	if(l == r) return tree2[i];
	int m = (l + r) / 2;
	if(k <= m) return query2(2 * i + 1, l, m, k);
	else return query2(2 * i + 2, m + 1, r, k);
}
void upd2(int i, int l, int r, int L, int R, int v, int x) {
	prop2(i, l, r);
	if(r < L || R < l) return;
	if(L <= l && r <= R) {
		lazy2[i] = x;
		prop2(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	if(minval2(2 * i + 1) <= v) upd2(2 * i + 1, l, m, L, R, v, x);
	if(minval2(2 * i + 2) <= v) upd2(2 * i + 2, m + 1, r, L, R, v, x);
	tree2[i] = min(minval2(2 * i + 1), minval2(2 * i + 2));
}

long long d, depth[N], t[M];
int n, m, u, v, par[N], prefchild[N], s[M], top[N], tin[N], tout[N], tininv[N];
vector<int> child[N];
queue<pair<long long, long long>> q[N];

int dfstime = 1;

void dfs(int x) {
	tin[x] = dfstime++;
	tininv[tin[x]] = x;
	for(int y : child[x]) {
		top[y] = (y == prefchild[x] ? top[x] : y);
		depth[y] += depth[x];
		dfs(y);
	}
	tout[x] = dfstime - 1;
}

void build2(int i, int l, int r) {
	if(l == r) {
		tree2[i] = tin[top[tininv[l]]];
		return;
	}
	int m = (l + r) / 2;
	build2(2 * i + 1, l, m);
	build2(2 * i + 2, m + 1, r);
	tree2[i] = min(tree2[2 * i + 1], tree2[2 * i + 2]);
}

// void printtree2() {
// 	for(int i = 1; i <= n; i++) {
// 		cout << query2(0, 1, n, i) << " ";
// 	}
// 	cout << endl;
// }

void processTrain(int i) {
	int top = tininv[query2(0, 1, n, tin[s[i]])];
	while(true) {
		int x = top;
		if(x == 1) break;
		int j = query1(0, 1, n, tin[par[x]] + 1, tout[par[x]]);
		q[par[x]].emplace(j == 0 ? 1 : 1 + t[j] + depth[par[x]], t[i] + depth[par[x]]);
		int k = prefchild[par[x]];
		prefchild[par[x]] = x;
		top = tininv[query2(0, 1, n, tin[par[x]])];
		// cout << "replace " << tin[x] << " with " << tin[top] << " on [" << tin[x] << ", " << tout[x] << "]" << endl;
		upd2(0, 1, n, tin[x], tout[x], tin[x], tin[top]);
		// printtree2();
		// cout << "replace " << tin[top] << " with " << tin[k] << " on [" << tin[k] << ", " << tout[k] << "]" << endl;
		upd2(0, 1, n, tin[k], tout[k], tin[top], tin[k]);
		// printtree2();
		// cout << endl;
	}
	upd1(0, 1, n, tin[s[i]], i);
}

struct event {
    long long time;
    int station;
    event(long long t, int s): time(t), station(s) {}
    bool operator<(const event &e) const {
        return time > e.time; //make_pair(time, station) > make_pair(e.time, e.station);
    }
};

long long T = 1;
priority_queue<event> pqL, pqR;

void processL() {
    T = pqL.top().time;
    while(!pqL.empty() && pqL.top().time == T) {
        event e = pqL.top(); pqL.pop();
        pqR.emplace(q[e.station].front().second, e.station);
        q[e.station].pop();
        if(!q[e.station].empty()) {
            pqL.emplace(q[e.station].front().first, e.station);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++) {
		cin >> u >> v >> d;
		par[v] = u;
		depth[v] = d;
		child[u].push_back(v);
		prefchild[u] = v;
	}
	top[1] = 1;
	dfs(1);
	// for(int i = 1; i <= n; i++) {
	// 	cout << "Station " << i << " " << tin[i] << " " << tout[i] << " " << tininv[i] << endl;
	// }
	for(int i = 1; i <= m; i++) {
		cin >> s[i] >> t[i];
	}
	build2(0, 1, n);
	// printtree2();
	for(int i = 1; i <= m; i++) {
		// cout << "Train " << i << endl;
		processTrain(i);
	}
	// cout << "got here" << endl;
	for(int i = 1; i <= n; i++) {
		// cout << "Station " << i << endl;
		if(!q[i].empty()) {
            pqL.emplace(q[i].front().first, i);
		}
	}
	vector<long long> ve;
    while(!pqL.empty() || !pqR.empty()) {
        if(pqR.empty()) {
            processL();
        }else {
            event e = pqR.top(); pqR.pop();
            if(T > e.time) {
                // cout << "Cannot switch " << e.station << " by time " << e.time << endl;
                long long switches = 0;
                for(long long t : ve) {
                    if(t < e.time) switches++;
                }
                cout << e.time << " " << switches << endl;
                return 0;
            }
            ve.push_back(e.time);
            // cout << "Switch station " << e.station << " at time " << T << endl;
            T++;
            if(!pqL.empty() && pqL.top().time == T) {
                processL();
            }
        }
    }
    cout << "-1 " << ve.size() << '\n';
}