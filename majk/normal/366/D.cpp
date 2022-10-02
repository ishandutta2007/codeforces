#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned int ui;
struct 	UnionFind {
	UnionFind(size_t N) : P(N, -1), comp(N) {}
	int find(int x) { while (P[x]> 0){x = P[x]-1;}return x; }
	bool united(int x, int y) { return find(x) == find(y); }
	bool unite(int x, int y) { x=find(x);y=find(y);if(x==y){return false;}--comp;if(P[x]>P[y]){swap(x,y);}P[x]+=P[y];P[y]= x+1;return true;}
	inline ui size(int u) { return -P[find(u)]; }
	vector<int> P;
	size_t comp;
};

typedef pair<int,int> pii;

#define x first
#define y second

int main() {
    int N, M; cin >> N >> M;
    vector<pair<pii,pii>> E(M);
    for (int i = 0; i < M; ++i) {
        int a,b,l,r; cin >> a >> b >> l >> r;
        E[i] = {{r,l},{a-1,b-1}};
    }

    sort(E.begin(),E.end());
    reverse(E.begin(),E.end());

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        UnionFind UF(N);
        for (int j = 0; j < M; ++j) {
            if (E[j].x.y <= E[i].x.y) {
                UF.unite(E[j].y.x, E[j].y.y);
                if (UF.united(0, N-1)) {
                    ans = max(E[j].x.x - E[i].x.y + 1, ans);
                    break;
                }
            }
        }
    }
    if (ans) cout << ans << endl;
    else cout << "Nice work, Dima!\n";
}