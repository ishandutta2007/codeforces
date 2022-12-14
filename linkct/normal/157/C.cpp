#include <cstdio>
#include <cstring>
const int MAXN = 2005;

int n, m; char s1[MAXN], s2[MAXN], s3[MAXN * 3];

int main(){
	int i, j, k, cnt, ans;
	scanf("%s%s", s1 + 1, s2 + 1);
	n = strlen(s1 + 1), m = strlen(s2 + 1);
	for(i = m; i < m + n; ++ i)
		s3[i] = s1[i - m + 1];
	k = n + (m - 1) * 2; ans = m;
	for(i = 1; i + m - 1 <= k; ++ i){
		for(j = cnt = 0; j < m; ++ j)
			if(s3[i + j] != s2[j + 1])
				++ cnt;
		if(cnt < ans) ans = cnt;
	} printf("%d\n", ans);
	return 0;
}