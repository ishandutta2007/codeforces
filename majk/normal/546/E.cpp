/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author majk
 */

#ifndef MAJK_LIB
#define MAJK_LIB

#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iomanip>
#include <set>
#include <functional>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
using namespace std;

#define x first
#define y second
typedef std::pair<int,int> pii; typedef long long ll; typedef unsigned long long ull; typedef unsigned int ui; typedef pair<ui,ui> puu;

template <typename T, typename U> std::istream&operator>>(std::istream&i, pair<T,U>&p) {i >> p.x >> p.y; return i;}
template<typename T>std::istream&operator>>(std::istream&i,vector<T>&t) {for(auto&v:t){i>>v;}return i;}
template <typename T, typename U> std::ostream&operator<<(std::ostream&o, const pair<T,U>&p) {o << p.x << ' ' << p.y; return o;}
template<typename T>std::ostream&operator<<(std::ostream&o,const vector<T>&t) {if(t.empty())o<<'\n';for(size_t i=0;i<t.size();++i){o<<t[i]<<" \n"[i == t.size()-1];}return o;}
template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T> bool in(T a, T b, T c) { return a <= b && b < c; }
ui logceil(int x) { return 8*sizeof(int)-__builtin_clz(x); }

namespace std { template<typename T,typename U>struct hash<pair<T,U>>{hash<T>t;hash<U>u;size_t operator()(const pair<T,U>&p)const{return t(p.x)^(u(p.y)<<7);}}; }
template<typename T,typename F>T bsh(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){l=m+1;r=m;}else{h=m-1;}}return r;}
template<typename F> double bshd(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){l=m;}else{h=m;}}return (l+h)/2;}
template<typename T,typename F>T bsl(T l,T h,const F&f){T r=-1,m;while(l<=h){m=(l+h)/2;if(f(m)){h=m-1;r=m;}else{l=m+1;}}return r;}
template<typename F> double bsld(double l,double h,const F&f,double p=1e-9){ui r=3+(ui)log2((h-l)/p);while(r--){double m=(l+h)/2;if(f(m)){h=m;}else{l=m;}}return (l+h)/2;}
template<typename T> T gcd(T a,T b) { if (a<b) swap(a,b); return b?gcd(b,a%b):a; }

template<typename T>class vector2:public vector<vector<T>>{public:vector2(){} vector2(size_t a,size_t b,T t=T()):vector<vector<T>>(a,vector<T>(b,t)){}};
template<typename T>class vector3:public vector<vector2<T>>{public:vector3(){} vector3(size_t a,size_t b,size_t c,T t=T()):vector<vector2<T>>(a,vector2<T>(b,c,t)){}};
template<typename T>class vector4:public vector<vector3<T>>{public:vector4(){} vector4(size_t a,size_t b,size_t c,size_t d,T t=T()):vector<vector3<T>>(a,vector3<T>(b,c,d,t)){}};
template<typename T>class vector5:public vector<vector4<T>>{public:vector5(){} vector5(size_t a,size_t b,size_t c,size_t d,size_t e,T t=T()):vector<vector4<T>>(a,vector4<T>(b,c,d,e,t)){}};


#endif
#ifndef MAJK_DINIC
#define MAJK_DINIC


// DINIC MAX-FLOW ALGORITHM. LOOK ELSEWHERE
template<typename T> struct Dinic {
	ui V, E;
	std::vector<ui> LastEdge, EdgeToProcess, BfsDistance, PrevEdge, EdgeTarget;
	std::vector<T> Capacity, Residual;

	Dinic(ui v, ui e = 0) : V(v), E(0), LastEdge(V, ui(-1)), BfsDistance(V), EdgeToProcess(V) {
		Capacity.reserve(2*e);
		Residual.reserve(2*e);
		EdgeTarget.reserve(2*e);
		PrevEdge.reserve(2*e);
	}

	void AddEdge(ui x, ui y, T c1 = 1, T c2 = 0) {
//		cerr << x << ' ' << y << endl;
		EdgeTarget.push_back(y);
		Capacity.push_back(c1);
		Residual.push_back(c1);
		PrevEdge.push_back(LastEdge[x]);
		LastEdge[x] = E++;
		EdgeTarget.push_back(x);
		Capacity.push_back(c2);
		Residual.push_back(c2);
		PrevEdge.push_back(LastEdge[y]);
		LastEdge[y] = E++;
	}

	T push(int x, int v, T flow) {
		if (x == v) return flow;
		for (ui &e = EdgeToProcess[x]; e != -1; e = PrevEdge[e]) {
			ui y = EdgeTarget[e];
			if (Residual[e] && BfsDistance[x] + 1 == BfsDistance[y]) {
				if (T f = push(y, v, min(flow, Residual[e]))) {
					Residual[e] -= f;
					Residual[e ^ 1] += f;
					return f;
				}
			}
		}
		return 0;
	}

	T GetMaxFlow(int u, int v) {
		T ret = 0;
		while (true) {
			fill(BfsDistance.begin(), BfsDistance.end(), (ui)-1);
			BfsDistance[u] = 0;
			std::queue<int> Q{{u}};
			while (!Q.empty()) {
				int x = Q.front(); Q.pop();
				for (int e = LastEdge[x]; e != ui(-1); e = PrevEdge[e]) {
					ui y = EdgeTarget[e];
					if (Residual[e] && BfsDistance[y] == ui(-1)) {
						Q.push(y);
						BfsDistance[y] = BfsDistance[x] + 1;
					}
				}

			}

			if (BfsDistance[v] == ui(-1)) break;
			copy(LastEdge.begin(), LastEdge.end(), EdgeToProcess.begin());
			while (T f = push(u, v, std::numeric_limits<T>::max())) ret += f;
		}

		return ret;
	}

	std::vector<bool> GetMinCut(int u) {
		std::queue<int> Q;
		Q.push(u);
		vector<bool> R(V, false);
		R[u] = true;
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int e = LastEdge[x]; e != -1; e = PrevEdge[e]) {
				int y = EdgeTarget[e];
				if (!R[y] && Residual[e] > 0) {
					Q.push(y);
					R[y] = true;
				}
			}
		}
		return R;
	}

	vector<std::tuple<ui, ui, T>> GetEdgesWithFlow() {
		vector<std::tuple<ui, ui, T>> Ans;
		for (ui u = 0; u < V; ++u) {
			for (ui e = LastEdge[u]; e != ui(-1); e = PrevEdge[e]) {
				if (Residual[e] < Capacity[e]) {
					Ans.push_back({u, EdgeTarget[e], Capacity[e] - Residual[e]});
				}
			}
		}
		return Ans;
	};
};
// DINIC MAX-FLOW ALGORITHM
#endif
#include <numeric>

class soldiertraveling {
public:
    void solve(istream& cin, ostream& cout) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N), B(N);
        cin >> A >> B;
        int sumA = accumulate(A.begin(),A.end(),0);
        int sumB = accumulate(B.begin(),B.end(),0);
        if (sumA != sumB) {
            cout << "NO\n";
            return;
        }

        Dinic<int> G(2*N+2);
        for (int i = 0; i < N; ++i) {
            G.AddEdge(0, i+1, A[i]);
            G.AddEdge(i+1, N+i+1, 100);
            G.AddEdge(N+i+1, 2*N+1, B[i]);
        }

        for (int i = 0; i < M; ++i) {
            int a, b; cin >> a >> b;
            G.AddEdge(a, b+N, 100);
            G.AddEdge(b, a+N, 100);
        }

        if (G.GetMaxFlow(0, 2*N+1) == sumA) {
            cout << "YES\n";
            vector2<int> Ans(N,N,0);
            for (int i = 0; i < G.E; i+=2) {
                int u = G.EdgeTarget[i];
                int v = G.EdgeTarget[i+1];
                int r = G.Residual[i+1];
                if (v != 0 && u != 2*N+1) {
                    Ans[v-1][u-(N+1)] = r;
                }
            }
            for (auto&ans:Ans) cout << ans;
        } else {
            cout << "NO\n";
        }

    }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	soldiertraveling solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
    return 0;
}