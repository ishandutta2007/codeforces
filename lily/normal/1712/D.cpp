#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

const int N = 1e5 + 5;

int n, K;
int a[N];
bool b[N];
const int INF = 1e9 + 1;
bool check(int mid) {
	int eliminate = (mid - 1) / 2;
	int cnt = 0;
	for (int i = 1; i <= n; i++) b[i] = 0;
	for (int i = 1; i <= n; i++) if (a[i] <= eliminate) cnt ++, b[i] = 1;
	int flag = 2;
	for (int i = 1; i < n; i++) {
		if (min(b[i] ? INF : a[i], b[i + 1] ? INF : a[i + 1]) >= mid) {
			flag = 0;
			break;
		}
		else if (max(b[i] ? INF : a[i], b[i + 1] ? INF : a[i + 1]) >= mid) {
			flag = 1;
		}
	}
	return cnt + flag <= K;
}

void work(){
	read(n); read(K);
	for (int i = 1; i <= n; i++) read(a[i]);
	int l = 1, r = 1e9;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}