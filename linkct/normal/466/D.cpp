#include <cstdio>
#define MAXN 2005
#define MOD 1000000007LL
typedef long long int ll;

int n, h, a[MAXN];
ll dp[MAXN][MAXN];

inline int max(int a, int b){return a > b ? a : b;}
inline int min(int a, int b){return a > b ? b : a;}
void add(ll& a, ll b){a = (a + b) % MOD;}
int main(){
	int i, open;
	scanf("%d%d", &n, &h);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	dp[1][0] = ((a[1] == h || a[1] == h - 1) ? 1 : 0);
	dp[1][1] = ((a[1] == h - 1) ? 1 : 0);
	for(i = 2; i <= n; ++ i){
		for(open = max(0, h - a[i] - 1); open <= min(i, h - a[i]); ++ open){
			if(a[i] + open == h){
				if(open) add(dp[i][open], dp[i - 1][open - 1]);
				add(dp[i][open], dp[i - 1][open]);
			}else if(a[i] + open == h - 1){
				add(dp[i][open], dp[i - 1][open + 1] * (open + 1));
				add(dp[i][open], dp[i - 1][open]);
				add(dp[i][open], dp[i - 1][open] * open);
			}
		}
	}
	printf("%d\n", (int)dp[n][0]);
	return 0;
}