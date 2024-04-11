#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef double db;
const int N = 2e5 + 10, K = 30;
int cnt[K];
int n;

int main() {
	int T;
	for(scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		for(int i = 0; i < K; i++) cnt[i] = 0;
		for(int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			for(int j = K - 1; j >= 0; j--) {
				if(a >> j & 1) {
					cnt[j]++;
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			int flag = 1;
			for(int j = 0; j < K; j++) {
				if(cnt[j] % i) {
					flag = 0;
				}
			}
			if(flag) printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}