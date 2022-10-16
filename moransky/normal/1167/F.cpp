#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 500005, P = 1e9 + 7;
int n, a[N];
LL c[2][N];
LL ask(int x, int m) {
	LL res = 0;
	for (; x; x -= x & -x) res += c[m][x];
	return res;
} 
void inline add(int x, LL k, int m) {
	for(; x <= n; x += x & -x) c[m][x] += k;
}
/*
id, val = x
c[i] = id*(N-id+1)
c[i] += (N-id+1)*sum{j | a[j]<a[id], j<id}
c[i] += id*sum{N-j+1 | a[j]<a[id], j>id}
*/
PII e[N];
int main(){
	LL ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &e[i].first), e[i].second = i;
	
	sort(e + 1, e + 1 + n);
	for (int i = 1; i <= n; i++) {
		int l = e[i].second, v = e[i].first;
		LL val = (LL)l * (n - l + 1) % P;
		val = (val + (LL)(n - l + 1) * ask(l - 1, 0)) % P;
		val = (val + (LL)l * (ask(n, 1) - ask(l, 1))) % P;
		add(l, l, 0);
		add(l, n - l + 1, 1);
		ans = (ans + val * v) % P;
	}
	printf("%lld\n", ans);
	return 0;
}