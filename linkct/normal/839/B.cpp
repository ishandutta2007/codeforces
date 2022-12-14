#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

struct Status{
	int a, b, c, sum;
	Status(){}
	Status(int i, int j, int k): a(i), b(j), c(k), sum(i + 2 * j + 3 * k) {}
	bool operator < (const Status &rhs) const{
		return sum < rhs.sum;
	}
}st[MAXN * MAXN * MAXN * 3];
int n, m, a[MAXN], f[MAXN * 3][MAXN][MAXN], cnt[5], d[5], tot;

inline int get(){return f[d[1]][d[2]][d[3]];}
inline void update(int &a, int b){if(a > b) a = b;}
int main(){
	int i, j, full, k, t;
	scanf("%d%d", &n, &m);
	full = n;
	for(i = 1; i <= m; ++ i){
		scanf("%d", &a[i]);
		while(a[i] >= 4 && full)
			a[i] -= 4, -- full;
	}
	if(full){
		for(i = 1; i <= m; ++ i)
			++ cnt[a[i]];
		for(i = 0; i <= cnt[1] + 2 * cnt[2] + 3 * cnt[3]; ++ i)
			for(j = 0; j <= cnt[2] + cnt[3]; ++ j)
				for(k = 0; k <= cnt[3]; ++ k)
					st[++ tot] = Status(i, j, k);
		sort(st + 1, st + 1 + tot);
		memset(f, 0x3f, sizeof(f));
		f[0][0][0] = 0;
		/*for(d[1] = 0; d[1] <= cnt[1]; ++ d[1])
			for(d[2] = 0; d[2] <= cnt[2]; ++ d[2])
				for(d[3] = 0; d[3] <= cnt[3]; ++ d[3]){
					st[++ tot] = Status(d[1], d[2], d[3], d[1] + d[2] * 2 + d[3] * 3);*/
		for(k = 1; k <= tot; ++ k){
			d[1] = st[k].a, d[2] = st[k].b, d[3] = st[k].c;
					int &cur = f[d[1]][d[2]][d[3]];
					for(i = 1; i <= 3; ++ i){
						if(d[i]){
							-- d[i];
							update(cur, get() + 1);
							++ d[i];
							for(j = i; j <= 3; ++ j){
								if(d[j]){
									if(i == j && d[j] == 1) continue;
									-- d[j], ++ d[j - 1];
									-- d[i], ++ d[i - 1];
									update(cur, get() + 1);
									++ d[j], -- d[j - 1];
									++ d[i], -- d[i - 1];
									if(j >= 2){
										-- d[j], ++ d[j - 2];
										-- d[i], ++ d[i - 1];
										update(cur, get() + 1);
										++ d[j], -- d[j - 2];
										++ d[i], -- d[i - 1];
									}
									if(i >= 2){
										-- d[j], ++ d[j - 1];
										-- d[i], ++ d[i - 2];
										update(cur, get() + 1);
										++ d[j], -- d[j - 1];
										++ d[i], -- d[i - 2];
									}
								}
							}
						}
					}
					//++ cur;
					/*printf("%d %d %d: %d\n", d[1], d[2], d[3], cur);
					if(cur <= full && cnt[1] - d[1] + cnt[2] - d[2] + (cnt[3] - d[3]) * 2 <= 2 * n){
						printf("YES\n");
						return 0;
					}*/
				}
		for(i = 0; i <= cnt[1]; ++ i)
			for(j = 0; j <= cnt[2]; ++ j)
				for(k = 0; k <= cnt[3]; ++ k)
					for(t = 0; t + k <= cnt[3]; ++ t)
						if(f[i + t][j][k] <= full && cnt[1] - i + cnt[2] - j + (cnt[3] - k - t) * 2 + t <= 2 * n){
							printf("YES\n");
							return 0;
						}
		printf("NO\n");
	}else{
		full = 2 * n;
		for(i = 1; i <= m; ++ i)
			full -= (a[i] + 1) / 2;
		printf("%s\n", full >= 0 ? "YES" : "NO");
	} return 0;
}