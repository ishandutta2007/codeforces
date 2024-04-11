#include<bits/stdc++.h>
using namespace std;

const int N = 22;

struct ele {
	int a, b;
}a[N], b[N];

int c[N], d[N];
int L[N][N], R[N][N];
int e[N];
int n, m;

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b;
	for(int i = 1; i <= m; i++) cin >> b[i].a >> b[i].b;
	for(int i = 1; i <= n; i++) if(a[i].a > a[i].b) swap(a[i].a, a[i].b);
	for(int i = 1; i <= m; i++) if(b[i].a > b[i].b) swap(b[i].a, b[i].b);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i].a == b[j].a && a[i].b == b[j].b) continue;
			if(a[i].a == b[j].a || a[i].a == b[j].b) {
				e[a[i].a] = 1;
				L[i][a[i].a] = 1, R[j][a[i].a] = 1;
			}
			if(a[i].b == b[j].a || a[i].b == b[j].b) {
				e[a[i].b] = 1;
				L[i][a[i].b] = 1, R[j][a[i].b] = 1;
			}
		}
	}
	int I = 0, num;
	for(int i = 1; i <= 9; i++) {
		//cout << I << " " << e[i] << " " << I + e[i] << endl;
		int tmp = e[i];
		I += tmp;
		if(e[i]) num = i;
	}
	int l = 1, r = 1;
	for(int i = 1; i <= n; i++) {
		int tmp = 0;
		for(int j = 1; j <= 9; j++) tmp += L[i][j];
		if(tmp >= 2) l = 0;
	}
	for(int i = 1; i <= m; i++) {
		int tmp = 0;
		for(int j = 1; j <= 9; j++) tmp += R[i][j];
		if(tmp >= 2) r = 0;
	}
	if(I == 1) cout << num << endl;
	else if(l && r) cout << 0 << endl;
	else cout << -1 << endl;
	return 0;
}