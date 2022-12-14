#include <bits/stdc++.h>
using namespace std;

int n, r[17], b[17], f[70005][305], bitc[70005], sr, sb, tp[17], N;

inline void update(int &x, int y){if(x < y) x = y;}
int main(){
	int i, j, k, cur, cnt[3], ans; char s[5];
	scanf("%d", &n);
	for(i = 0; i < n; ++ i){
		scanf("%s%d%d", s, &r[i], &b[i]);
		sr += r[i], sb += b[i];
		if(s[0] == 'R') tp[i] = 0;
		else tp[i] = 1;
	} memset(f, -1, sizeof(f));
	ans = max(sr, sb);
	f[0][0] = 0;
	for(i = 0, N = 1 << n; i < N; ++ i){
		bitc[i] = bitc[i >> 1] + (i & 1);
		cnt[0] = cnt[1] = 0;
		for(j = 0; j < n; ++ j)
			if(i & (1 << j))
				++ cnt[tp[j]];
		for(j = 0; j <= bitc[i] * (bitc[i] - 1) / 2; ++ j)
			if((cur = f[i][j]) >= 0)
				for(k = 0; k < n; ++ k)
					if((i & (1 << k)) == 0)
						update(f[i | (1 << k)][j + min(cnt[0], r[k])], cur + min(cnt[1], b[k]));
	}
	for(i = 0; i <= n * (n - 1) / 2; ++ i)
		if((cur = f[N - 1][i]) >= 0)
			ans = min(ans, max(sr - i, sb - cur));
	printf("%d\n", ans + n);
	return 0;
}