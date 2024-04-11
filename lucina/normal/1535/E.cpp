#include <bits/stdc++.h>
#define st first
#define nd second
#define PQ priority_queue
#define MP make_pair

using ll = long long ;
using namespace std;
using pii = pair<int,int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
const int LOG = 20;
const int N = 3e5 + 10;
const int MOD = 0;

int par[N][LOG], lg[N], depth[N], a[N], c[N];

void add_node(int node) {
	depth[node] = par[node][0] + 1;
	for (int i = 1; i<= lg[depth[node]]; i ++) {
		par[node][i] = par[par[node][i - 1]][i - 1];
	}
}

void func(int node, int w) {
	ll val = 0;
	int gain = 0, ma = depth[node];
	while (gain < w && a[node] > 0) {
		int cur = node;
		for(int i = lg[depth[node]]; i >= 0; i--) {
			if (i <= lg[depth[cur]] && a[par[cur][i]] > 0) {
				cur = par[cur][i];
			}
			if (cur == 0) break;
		}
		int u = min(w - gain, a[cur]);
		gain += u;
		a[cur] -= u;
		val += 1LL * u * c[cur];
	}
	cout << gain <<  " " <<  val << endl;

}


int main(){
    cin.tie(0)->sync_with_stdio(false);
	int q;
	cin >> q >> a[0] >> c[0];
	// scanf("%d %d %d", &q, &a[0], &c[0]);
	lg[0] = -1;
	lg[1] = 0;
	lg[2] = 1;
	int k = 4;
	for(int i = 3; i <= 3e5; i ++) {
		lg[i] = lg[i - 1];
		if (i == k) {
			lg[i] ++;
			k *= 2;
		}
	}
	for(int i = 1; i <= q; i++) {
		int id;
		cin >> id;
		if (id == 1) {
		    cin >> par[i][0] >> a[i] >> c[i];
			add_node(i);
		} else {
			int node, w;
			cin >> node >> w;
			func(node, w);
		}
	}


}