/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Majk
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>
#include <functional>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

#define x first
#define y second
constexpr int MOD = 1000000007;

typedef std::pair<int,int> pii;
typedef long long ll;

template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}

namespace std {
    template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}};
}
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

// #include "../l/mod.h"

#include <cstring>

int B[3000];
int V[3000];
int D[3000][3000];
pii F1[3000], F2[3000], F3[3000];
pii T1[3000], T2[3000], T3[3000];


int P,Q,R,S;
int Ans;

class TaskB {
public:
	vector<vector<int>> E;
	int N, M;

	void bfs(int u) {
		B[0] = u;
		memset(V, 0, 3000*sizeof(int));

		V[u] = 1;

		int f = 0, t = 1, s = 1;
		int d = 1;
		while (f != t) {
			for (int i = f; i < t; ++i) {
				for (int v: E[B[i]]) {
					if (!V[v]) {
						V[v] = 1;
						B[s++] = v;
						D[u][v] = d;
					}
				}
			}
			++d;
			f = t;
			t = s;
		}
	}


	void check(int i, int j, pii a, pii b) {
		if (D[i][j] == 0) return;
		if (a.y == i || a.y == j || a.x == 0) return;
		if (b.y == i || b.y == j || b.x == 0) return;
		if (b.y == a.y) return;
		int cur = a.x + b.x + D[i][j];
		if (cur > Ans) {
			Ans = cur;
			P = a.y;
			Q = i;
			R = j;
			S = b.y;
		}
	}

	void solve(istream& cin, ostream& cout) {
		cin >> N >> M;
		E.resize(N);

		for (int i = 0; i < M; ++i) {
			int u,v; cin >> u >> v;
			E[--u].push_back(--v);
		}

		for (int i = 0; i < N; ++i) {
			bfs(i);
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;

				int d = D[i][j];
				if (d > F1[i].x) { F3[i] = F2[i]; F2[i] = F1[i]; F1[i] = {d,j}; }
				else if (d > F2[i].x) { F3[i] = F2[i]; F2[i] = {d,j}; }
				else if (d > F3[i].x) { F3[i] = {d,j}; }

				d = D[j][i];
				if (d > T1[i].x) { T3[i] = T2[i]; T2[i] = T1[i]; T1[i] = {d,j}; }
				else if (d > T2[i].x) { T3[i] = T2[i]; T2[i] = {d,j}; }
				else if (d > T3[i].x) { T3[i] = {d,j}; }
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j) continue;
				check(i, j, T1[i], F1[j]);
				check(i, j, T2[i], F1[j]);
				check(i, j, T3[i], F1[j]);
				check(i, j, T1[i], F2[j]);
				check(i, j, T2[i], F2[j]);
				check(i, j, T3[i], F2[j]);
				check(i, j, T1[i], F3[j]);
				check(i, j, T2[i], F3[j]);
				check(i, j, T3[i], F3[j]);
			}
		}

		cout << P+1 << ' ' << Q+1 << ' ' << R+1 << ' ' << S+1 << endl;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	TaskB solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}