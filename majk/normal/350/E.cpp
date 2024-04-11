#include <iostream>
#include <vector>

using namespace std; 
typedef pair<int,int> pii;
#define x first
#define y second

int main() {
    int N,M,K; cin >> N >> M >> K;
    if (K == N) { cout << -1 << endl; return 0; }

    vector<int> V(K); 
    for(int&v:V) cin >> v;
    vector<bool> U(N, false);
    for (int &v:V) U[--v] = true;
    int last = N-1;
    while (U[last]) --last;
 
    vector<pii> E;
    for (int i = 0; i < N; ++i) {
        if (i!=last) E.emplace_back(i,last);
    }

    for (int i = 1; i < V.size(); ++i) {
        for (int j = i+1; j < V.size(); ++j) {
            E.emplace_back(V[i],V[j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i!=last && !U[i]) {
            for (int j = 0; j < N; ++j) {
                if (j!=last && (U[j] || j < i)) {
                    E.emplace_back(i,j);
                }
            }
        }
    }

    if (M > E.size()) { cout << -1 << endl; return 0; }
    for (int i = 0; i < M; ++i) {
        cout << E[i].x+1 << ' ' << E[i].y+1 << '\n';
    }
}