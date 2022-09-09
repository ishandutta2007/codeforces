#include<bits/stdc++.h>
using namespace std;

const int N = 200000 + 10;

struct ele {
	int w, num;
}a[N];

int f[N];
int n, m;

inline bool cmp(ele a, ele b) {
	return a.w < b.w;
}
inline bool cmp2(ele a, ele b) {
	return a.num < b.num;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i].w);
		a[i].num = i;
	}
	sort(a + 1, a + n + 1, cmp);
	int last = 1, tmp = 0;
	for(int i = 2; i <= n; i++) {
		if(a[i].w != a[i - 1].w) {
			tmp += i - last;
			last = i;
		}
		f[a[i].num] = tmp;
	}
	sort(a + 1, a + n + 1, cmp2);
	for(int i = 1; i <= m; i++) {
		int b, c;
		scanf("%d %d", &b, &c);
		if(a[b].w > a[c].w) f[b]--;
		if(a[b].w < a[c].w) f[c]--;
	}
	for(int i = 1; i <= n; i++) printf("%d ", f[i]);
	return 0;
}