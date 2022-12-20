#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef double db;
using namespace std;

const int maxn = 1010;
int a[maxn][5],cnt[3],n,t;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			for(int j = 0; j < 5; ++j)
				scanf("%d", &a[i][j]);
		bool flag = 1;
		for(int s1 = 0; s1 < 5 && flag; ++s1)
			for(int s2 = s1 + 1; s2 < 5 && flag; ++s2) {
				cnt[0] = cnt[1] = cnt[2] = 0;
				for(int i = 1; i <= n; ++i) cnt[0] += a[i][s1];
				for(int i = 1; i <= n; ++i) cnt[1] += a[i][s2];
				for(int i = 1; i <= n; ++i) cnt[2] += a[i][s1] || a[i][s2];
				if(cnt[2] == n && cnt[0] >= n / 2 && cnt[1] >= n / 2) flag = 0;
			}
		printf("%s\n", flag ? "NO" : "YES");
	}
	return 0;
}