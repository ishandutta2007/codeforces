#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define forgp(u, g, v) for(int iu = 0, v; iu < (int)g[u].size() && (v = g[u][iu], 1); iu++)
#define mp make_pair
#define siz(v) (int)(v).size()
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int N = 50;
int L, R;
vector<int> e[N], c[N];

void adde(int u, int v, int w) {
	e[u].push_back(v), c[u].push_back(w);
}

int main() {
	scanf("%d%d", &L, &R);	
	adde(31, 32, 1);
	int k = 1;
	for(int i = 30; i >= 11; i--) {
		adde(i, i + 1, k);
		for(int j = 0; j < (int)e[i + 1].size(); j++) {
			adde(i, e[i + 1][j], c[i + 1][j]);
		}
		k <<= 1;
	}
	adde(1, 32, L);
	int b = L;
	for(int i = 20; i >= 0; i--) {
		if(((R - L) >> i) & 1) {
			adde(1, 31 - i, b);
			b += (1 << i);
		}
	}
	printf("YES\n");
	int m = 0;
	for(int i = 1; i <= 32; i++) {
		m += e[i].size();
	}
	printf("%d %d\n", 32, m);
	for(int i = 1; i <= 32; i++) {
		for(int j = 0; j < (int)e[i].size(); j++) {
			printf("%d %d %d\n", i, e[i][j], c[i][j]);
		}
	}
	return 0;
}