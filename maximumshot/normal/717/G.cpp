#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <conio.h>

using namespace std;

int const inf = 1000 * 1000 * 1000;

int n, m, x;
string text;
vector< string > word;
vector< int > p;

int N, S, T;
vector< vector< int > > g;

struct Edge {
	int from, to, Capacity, flow, Cost;
	Edge() : from(-1), to(-1), Capacity(0), flow(0), Cost(0) {}
	Edge(int from, int to, int Capacity, int Cost) : from(from), to(to), Capacity(Capacity), flow(0), Cost(Cost) {}
	inline int get_to(int u) const {
		if (u == from) return to;
		else return from;
	}
};

vector< Edge > ed;

inline void add_edge(int from, int to, int Capacity, int Cost) {
	g[from].push_back((int)ed.size());
	ed.push_back(Edge(from, to, Capacity, Cost));
	g[to].push_back((int)ed.size());
	ed.push_back(Edge(to, from, 0, -Cost));
}

pair< int, int > BellmanFord() {
	vector< int > dist(N, inf);
	vector< int > par(N, -1);
	dist[S] = 0;
	int ok = 1;
	for (int ITER = 0; ITER < N;ITER++) {
		//cout << ITER << " ";
		for (int u, v, w, iter = 0; iter < (int)ed.size(); iter++) {
			if (ed[iter].flow >= ed[iter].Capacity) continue;
			u = ed[iter].from;
			v = ed[iter].to;
			w = ed[iter].Cost;
			if (dist[u] != inf && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				par[v] = iter;
			}
		}
	}
	//if (dist[T] == inf) return make_pair(inf, 0);
	int mn = inf, res = 0;
	//cout << "\n\ndist = " << dist[T] << ", par = " << par[T] << " " << (int)ed.size() << "\n";
	//cout << "way : ";
	for (int id, u = T;par[u] != -1; u = ed[par[u]].get_to(u)) {
		//cout << u << " " << par[u] << " " << ed[par[u]].get_to(u) << "\n";
		//_getch();
		id = par[u];
		mn = min(mn, ed[id].Capacity - ed[id].flow);
	}
	for (int id, u = T;par[u] != -1; u = ed[par[u]].get_to(u)) {
		id = par[u];
		ed[id].flow += mn;
		res += mn * ed[id].Cost;
		ed[id ^ 1].flow -= mn;
	}
	//cout << "push = " << mn << "\n";
	//_getch();
	return make_pair(dist[T], res);
}

int mcmf() {
	int res = 0;
	pair< int, int > add;
	while (1) {
		add = BellmanFord();
		if (add.second)
			res += add.second;
		else
			break;
	}
	return -res;
}

void print_net() {
	cout << "ok!!!!\n";
	fstream fout("output.txt");
	for (int i = 0; i < (int)ed.size(); i++) {
		fout << ed[i].from << " " << ed[i].to << " [" << ed[i].Capacity << "," << ed[i].Cost << "]\n";
	}
}

bool solve() {

	cin >> n;

	cin >> text;

	cin >> m;

	word.resize(m);
	p.resize(m);

	for (int i = 0; i < m; i++) {
		cin >> word[i] >> p[i];
	}

	cin >> x;

	S = n;
	T = n + 1;
	N = n + 2;

	g.resize(N);

	add_edge(S, 0, x, 0);
	add_edge(n - 1, T, inf, 0);

	for (int i = 0; i + 1 < n; i++) {
		add_edge(i, i + 1, inf, 0);
	}

	for (int L, i = 0; i < m; i++) {
		L = (int)word[i].size();
		for (int j = 0; j + L - 1 < n; j++) {
			if (text.substr(j, L) == word[i]) {
				if (j + L < n) {
					add_edge(j, j + L, 1, -p[i]);
				} else {
					add_edge(j, T, 1, -p[i]);
				}
			}
		}
		//cout << "\n";
	}

	//_getch();

	//print_net();
	
	cout << mcmf() << '\n';

	return true;
}

int main() {
	
	//while (solve());
	solve();
	
	return 0;
}