#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

const int N = 105; 

int n;
int a[N], b[N];
pii c[N], d[N];

void work() {
	read(n);
	for (int i = 1; i<= n; i++) read(a[i]), c[i] = {a[i], i};
	for (int i = 1; i<= n; i++) read(b[i]), d[i] = {b[i], i};
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	puts("");
	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	puts("");
}


int main() {
	int T;
	read(T);
	while (T--) work();


}