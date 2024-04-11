#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

typedef unsigned int ui;
typedef pair<int,int> pii;

template <typename T> struct bounded_priority_queue {
	inline bounded_priority_queue(ui X) : A(X), B(0), s(0) {}
	inline void push(ui L, T V) { B = max(B, L); A[L].push(V); ++s; }
	inline const T &top() const { return A[B].front(); }
	inline void pop() { --s; A[B].pop(); while (B > 0 && A[B].empty()) --B; }
	inline bool empty() const { return A[B].empty(); }
	inline void clear() { s = B = 0; for (auto &a: A) a = queue<T>(); }
	inline ui size() const { return s; }
private:
	vector<queue<T>> A; ui B; int s;
};
// PUSH RELABEL MAX-FLOW
template<class T>
struct Edge {
	ui u, v; T c, f; ui i;
	inline bool hasResidual() const { return c > f; }
};

template<class T>
struct PushRelabel {
	ui V;
	vector<Edge<T>> E;
	vector<T> excess;
	vector<ui> level,levelCount,LastEdge,PrevEdge;
	vector<bool> active;
	bounded_priority_queue<ui> Q;

	PushRelabel(ui n) : V(n), excess(n), level(n), levelCount(n+1), active(n), Q(n), LastEdge(n, ui(-1)) {}

	void AddEdge(ui u, ui v, T c = 1) {
		PrevEdge.push_back(LastEdge[u]);
		LastEdge[u] = (ui)E.size();
		E.push_back({u, v, c, 0, 0});
		PrevEdge.push_back(LastEdge[v]);
		LastEdge[v] = (ui)E.size();
		E.push_back({v, u, 0, 0, 0});
	}

	void activate(ui vertex) {
		if (!active[vertex] && excess[vertex] > 0 && level[vertex] < V) {
			active[vertex] = true;
			Q.push(level[vertex], vertex);
		}
	}

	void pushFlow(int f) {
		Edge<T> &e = E[f];
		T flow = min(excess[e.u], e.c - e.f);
		if (level[e.u] == level[e.v] + 1 && flow > T(0)) {
			e.f += flow;
			E[f^1].f -= flow;
			excess[e.v] += flow;
			excess[e.u] -= flow;
			activate(e.v);
		}
	}

	inline void setLevel(ui vertex, ui newLevel) {
		--levelCount[level[vertex]];
		level[vertex] = newLevel;
		++levelCount[level[vertex]];
		activate(vertex);
	}

	void gap(ui k) {
		for (ui v = 0; v < V; v++) {
			if (level[v] >= k) {
				setLevel(v, max(level[v], V));
			}
		}
	}

	void raise(ui vertex) {
		ui newLevel = V;
		for (ui e = LastEdge[vertex]; e != ui(-1); e = PrevEdge[e]) {
			if (E[e].hasResidual()) {
				newLevel = min(newLevel, level[E[e].v] + 1);
			}
		}
		setLevel(vertex, newLevel);
	}

	void discharge(ui vertex) {
		active[vertex] = false;
		for (ui e = LastEdge[vertex]; e != ui(-1); e = PrevEdge[e]) {
			pushFlow(e);
			if (excess[vertex] <= 0) { return; }
		}

		if (levelCount[level[vertex]] == 1) {
			gap(level[vertex]);
		} else {
			raise(vertex);
		}
	}

	T GetMaxFlow(ui source, ui sink) {
		fill(level.begin(), level.end(), 0);
		fill(excess.begin(), excess.end(), T(0));
		fill(levelCount.begin(), levelCount.end(), 0);
		fill(active.begin(), active.end(), false);
		Q.clear();

		for (ui e = LastEdge[source]; e != ui(-1); e = PrevEdge[e]) excess[source] += E[e].c;
		levelCount[0] = V;
		activate(source);
		active[sink] = true;
		while (!Q.empty()) {
			ui v = Q.top(); Q.pop();
			discharge(v);
		}
		return excess[sink];
	}
};
#define x first
#define y second

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for (int &a: A) cin >> a;
    vector<pair<int,int>> E(M);
    for (auto&e:E) { cin >> e.x >> e.y; --e.x; --e.y; }
    unordered_map<int, vector<pii>> W; 
    for (int j = 0; j < N; ++j) {
        int a = A[j];
        for (int i = 2; i*i <= a; ++i) {
            if (a%i == 0) {
                int c = 0;
                while (a%i == 0) { a/=i; ++c; }
                W[i].emplace_back(j,c);
            }
        }
        if (a!=1) W[a].emplace_back(j,1);
    }

    int ans = 0;
    for (auto &w:W) {
        vector<int> I(N, 0);
        PushRelabel<int> P(w.y.size()+2);
        for (int i = 0; i < w.y.size(); ++i) {
            I[w.y[i].x] = i+1;
            if (w.y[i].x % 2) P.AddEdge(0, i+1, w.y[i].y);
            else P.AddEdge(i+1, w.y.size()+1, w.y[i].y);
        }
        for (pii e:E) {
            if (I[e.x] && I[e.y]) {
                if (e.x % 2) P.AddEdge(I[e.x],I[e.y],50);
                else P.AddEdge(I[e.y],I[e.x],50);
            }
        }
        ans += P.GetMaxFlow(0, w.y.size()+1);
    }
    cout << ans << endl;

}