#include <cstdio>
const int MAXN = 100005;
typedef long long int LL;

int n, q, seq[MAXN], dif[MAXN], s[MAXN], top, lft[MAXN], rht[MAXN];

inline int abs(int x){return x >= 0 ? x : -x;}
int main(){
	int i, j, l, r; LL ans;
	scanf("%d%d", &n, &q);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &seq[i]);
		dif[i] = i == 1 ? 0 : abs(seq[i] - seq[i - 1]);
	}
	for(i = 1; i <= q; ++ i){
		scanf("%d%d", &l, &r);
		if(l == r){
			printf("0\n");
			continue;
		} ++ l; top = 0;
		for(j = l; j <= r; ++ j){
			while(top && dif[s[top]] < dif[j]) -- top;
			lft[j] = s[top];
			if(top && dif[s[top]] == dif[j]) s[top] = j;
			else s[++ top] = j;
		} top = 0;
		for(j = r; j >= l; -- j){
			while(top && dif[s[top]] <= dif[j]) -- top;
			rht[j] = s[top];
			s[++ top] = j;
		} ans = 0LL;
		for(j = l; j <= r; ++ j){
			if(!lft[j]) lft[j] = l - 1;
			if(!rht[j]) rht[j] = r + 1;
			ans += LL(j - lft[j]) * (rht[j] - j) * dif[j];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}