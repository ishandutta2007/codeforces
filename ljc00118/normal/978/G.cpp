#include<bits/stdc++.h>
using namespace std;

const int N = 1000 + 10;

struct ele {
	int a, b, c, num;
}a[N], b[N], c[N];

int f[N], w[N];
int n, m;
int head = 1, tail = 0, di = 1, kaoshi = 1;

inline bool cmp(ele a, ele b) {
	return a.a < b.a;
}
inline bool cmp2(ele a, ele b) {
	return a.b < b.b;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d %d %d", &a[i].a, &a[i].b, &a[i].c);
		w[a[i].b] = a[i].c;
		c[i] = a[i];
		a[i].num = i;
	}
	sort(a + 1, a + m + 1, cmp);
	sort(c + 1, c + m + 1, cmp2);
	for(int i = 2; i <= m; i++) {
		if(c[i].b == c[i - 1].b) {
			printf("-1");
			return 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		while(di <= m && a[di].a <= i) {
			b[++tail] = a[di++];
		}
		if(kaoshi <= m && i == c[kaoshi].b) {
			if(w[i] != 0) {
				printf("-1");
				return 0;
			}
			f[i] = m + 1;
			kaoshi++;
			continue;
		}
		while(b[head].c == 0 && head <= tail) head++;
 		if(tail < head) f[i] = 0;
		else {
			sort(b + head, b + tail + 1, cmp2);
			f[i] = b[head].num;
			b[head].c--;
			w[b[head].b]--;
		}
	}
	for(int i = 1; i <= n; i++) printf("%d ", f[i]);
	return 0;
}