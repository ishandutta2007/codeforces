#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int INF = 1000000000;
const int Maxn = 2000005;
const int Maxm = 1004;

int n;
int X[Maxn], Y[Maxn];
vector <int> unX, unY;
bool B[Maxm][Maxm];
bool V[Maxm][Maxm], H[Maxm][Maxm];
int num1[Maxm][Maxm], num2[Maxm][Maxm];
int col[Maxn];

struct edge {
	int a, b, cap, flow;
};

int a, b;
int N, s, t, d[Maxn], ptr[Maxn], q[Maxn];
vector<edge> e;
vector<int> g[Maxn];
bool inplay[Maxn];
int resp[Maxn];
int partner[Maxn];

void traverseGood(int v);

void traverseBad(int v)
{
    if (resp[v]) { assert(resp[v] == -1); return; }
    resp[v] = -1;
    for (int i = 0; i < g[v].size(); i++) {
        int ind = g[v][i];
        if (v < a && e[ind].b >= a || v >= a && e[ind].b < a)
            traverseGood(e[ind].b);
    }
}

void traverseGood(int v)
{
    if (resp[v]) { assert(resp[v] == 1); return; }
    resp[v] = 1;
    if (partner[v]) traverseBad(partner[v]);
}

void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}

bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, N * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, N * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        unX.push_back(X[i]);
        unY.push_back(Y[i]);
    }
    sort(unX.begin(), unX.end()); unX.erase(unique(unX.begin(), unX.end()), unX.end());
    sort(unY.begin(), unY.end()); unY.erase(unique(unY.begin(), unY.end()), unY.end());
    for (int i = 0; i < n; i++) {
        int indx = lower_bound(unX.begin(), unX.end(), X[i]) - unX.begin() + 1;
        int indy = lower_bound(unY.begin(), unY.end(), Y[i]) - unY.begin() + 1;
        B[indx][indy] = true;
    }
    a = 1;
    for (int i = 1; i <= unX.size(); i++) {
        int lef = 1, rig = int(unY.size());
        while (lef <= rig)
            if (!B[i][lef]) lef++;
            else if (!B[i][rig]) rig--;
            else break;
        for (int j = lef, l; j <= rig; j = l) {
            l = j;
            while (B[i][l] == B[i][j]) {
                H[i][l] = true;
                if (!B[i][l]) num1[i][l] = a;
                l++;
            }
            if (!B[i][j]) a++;
        }
    }
    b = a;
    for (int j = 1; j <= unY.size(); j++) {
        int lef = 1, rig = int(unX.size());
        while (lef <= rig)
            if (!B[lef][j]) lef++;
            else if (!B[rig][j]) rig--;
            else break;
        for (int i = lef, l; i <= rig; i = l) {
            l = i;
            while (B[l][j] == B[i][j]) {
                V[l][j] = true;
                if (!B[l][j]) num2[l][j] = b;
                l++;
            }
            if (!B[i][j]) b++;
        }
    }
    N = b + 1;
    for (int i = 1; i < a; i++)
        add_edge(0, i, 1);
    for (int i = a; i < b; i++)
        add_edge(i, N - 1, 1);
    for (int i = 1; i <= unX.size(); i++)
        for (int j = 1; j <= unY.size(); j++)
            if (num1[i][j] > 0 && num2[i][j] > 0)
                add_edge(num1[i][j], num2[i][j], 1);
    s = 0, t = N - 1;
    int tot = dinic();
    queue <int> Q;
    for (int i = 0; i < e.size(); i++)
        if (e[i].a < a && e[i].b >= a && e[i].flow > 0) {
            inplay[e[i].a] = inplay[e[i].b] = true;
            partner[e[i].a] = e[i].b;
            partner[e[i].b] = e[i].a;
        }
    for (int i = 0; i < e.size(); i++)
        if (e[i].a == 0) {
            if (e[i].flow == 0)
                traverseBad(e[i].b);
        } else if (e[i].b == N - 1) {
            if (e[i].flow == 0)
                traverseBad(e[i].a);
        }
    for (int i = 1; i < b; i++)
        if (resp[i] == 0) traverseBad(i);
    for (int i = 1; i <= unX.size(); i++)
        for (int j = 1; j <= unY.size(); j++) {
            if (num1[i][j] > 0 && inplay[num1[i][j]] && resp[num1[i][j]] > 0)
                H[i][j] = false;
            if (num2[i][j] > 0 && inplay[num2[i][j]] && resp[num2[i][j]] > 0)
                V[i][j] = false;
        }
    int inter = 0;
    for (int i = 1; i <= unX.size(); i++)
        for (int j = 1; j <= unY.size(); j++)
            inter += H[i][j] && V[i][j];
    vector <iii> seq;
    for (int j = 1; j <= unY.size(); j++) {
        int i = 1;
        while (i <= unX.size())
            if (!V[i][j]) i++;
            else {
                seq.push_back(iii(j, ii(i, i)));
                while (i <= unX.size() && V[i][j]) {
                    seq.back().second.second = i;
                    i++;
                }
            }
    }
    printf("%d\n", int(seq.size()));
    for (int i = 0; i < seq.size(); i++)
        printf("%d %d %d %d\n", unX[seq[i].second.first - 1], unY[seq[i].first - 1],
                                unX[seq[i].second.second - 1], unY[seq[i].first - 1]);
    seq.clear();
    for (int i = 1; i <= unX.size(); i++) {
        int j = 1;
        while (j <= unY.size())
            if (!H[i][j]) j++;
            else {
                seq.push_back(iii(i, ii(j, j)));
                while (j <= unY.size() && H[i][j]) {
                    seq.back().second.second = j;
                    j++;
                }
            }
    }
    printf("%d\n", int(seq.size()));
    for (int i = 0; i < seq.size(); i++)
        printf("%d %d %d %d\n", unX[seq[i].first - 1], unY[seq[i].second.first - 1],
                                unX[seq[i].first - 1], unY[seq[i].second.second - 1]);
    return 0;
}