#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1005, P = 998244353;
int power(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}
struct Node{
	int x, y, w;
	bool operator < (const Node &x) const {
		return w < x.w;
	}
}e[N * N];
int n, m, r, c, len = 0, f[N * N];
int sx[N * N], sy[N * N], pre[N * N], sum[N * N];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int w; scanf("%d", &w);
			e[++len] = (Node) { i, j, w };
		}
	}
	scanf("%d%d", &r, &c);
	sort(e + 1, e + 1 + len);
	
	for (int i = 1, j = 0; i <= len; i++) {
		if(i > 1 && e[i].w != e[i - 1].w) j = i - 1;
		int x = e[i].x, y = e[i].y;
		f[i] = ((((LL)sum[j] + ((LL)j * ((LL)x * x % P + (LL)y * y % P) % P)) + pre[j] - 2 * (LL)x * sx[j] - 2 * (LL)y * sy[j]) % P + P) % P;
		f[i] = ((LL)f[i] * power(j, P - 2) % P + P) % P;
		if(e[i].x == r && e[i].y== c) {
			printf("%d\n", f[i]);
			return 0;
		}
		
		sum[i] = ((LL)sum[i - 1] + f[i]) % P;
		pre[i] = ((LL)pre[i - 1] + (((LL)x * x % P + (LL)y * y % P) % P)) % P;
		sx[i] = (sx[i - 1] + x) % P;
		sy[i] = (sy[i - 1] + y) % P; 
	}
	return 0;
}