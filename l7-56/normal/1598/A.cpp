#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef double db;
using namespace std;

const int maxn = 110;
int t,n,mp[2][maxn];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < 2; ++i)
			for(int j = 1; j <= n; ++j)
				scanf("%1d", &mp[i][j]);
		int flag = 0;
		for(int i = 1; i <= n; ++i)
			flag |= (mp[0][i] && mp[1][i]);
		printf("%s\n", flag ? "NO" : "YES");
	}
	return 0;
}