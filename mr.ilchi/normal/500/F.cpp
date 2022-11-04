#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4000+10;
const int MAXB = 4000+10;

int n,p;
int dp[MAXN][MAXB],dpr[MAXN][MAXB];
pair<int,int> range[MAXN];

struct item{
	int c,h,t;
	item(){}
	item(int c, int h, int t) : c(c), h(h), t(t) {}
	bool operator < (const item &other) const { return t < other.t; }
}a[MAXN];

int main(){
	scanf("%d%d", &n, &p);
	for (int i=0; i<n; i++)
		scanf("%d%d%d", &a[i].c, &a[i].h, &a[i].t);
	sort(a, a+n);
	int last = 0;
	for (int i=0; i<=n; i++){
		if (i==n || a[last].t+p <= a[i].t){
			for (int j=last; j != i; j++)
				range[j] = pair<int,int>(last,i-1);
			for (int k=a[last].c; k != MAXB; k++)
				dp[last][k] = a[last].h;
			for (int j=last+1; j != i; j++)
				for (int k=0; k != MAXB; k++)
					dp[j][k] = max(dp[j-1][k], ((k<a[j].c) ? (0) : (dp[j-1][k-a[j].c] + a[j].h)));
			for (int k=a[i-1].c; k != MAXB; k++)
				dpr[i-1][k] = a[i-1].h;
			for (int j=i-2; j >= last; j--)
				for (int k=0; k != MAXB; k++)
					dpr[j][k] = max(dpr[j+1][k], ((k<a[j].c) ? (0) : (dpr[j+1][k-a[j].c] + a[j].h))); 
			last = i;
		}
	}
	int que; scanf("%d", &que);
	for (int o=0; o<que; o++){
		int t,b; scanf("%d%d", &t, &b);
		int lo = n, hi = -1;
		for (int i=0; i<n; i++) if (a[i].t<=t && t<a[i].t+p)
			lo = min(lo, i), 
			hi = max(hi, i);
		if (hi == -1)
			printf("0\n");
		else{
			if (range[lo].first != range[hi].first){
				int ans = 0;
				for (int k=0; k<=b; k++)
					ans = max(ans, dpr[lo][k] + dp[hi][b-k]);
				printf("%d\n", ans);
			}else if (lo == range[lo].first)
				printf("%d\n", dp[hi][b]);
			else
				printf("%d\n", dpr[lo][b]);
		}
	}
	return 0;
}