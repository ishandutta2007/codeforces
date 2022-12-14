#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXN = 1000005;

int n, p[MAXN], cnt[MAXN], cnt2[MAXN], cnt_[MAXN], cnt2_[MAXN];
LL tot[MAXN], tot_[MAXN], tot2[MAXN], tot2_[MAXN];

void add(int st, int l, int r){
	++ cnt[l];
	++ cnt_[r];
	tot[l] += st;
	tot_[r] += st + r - l;
}
void addRev(int st, int l, int r){
	++ cnt2[l];
	++ cnt2_[r];
	tot2[l] += st;
	tot2_[r] += st - r + l;
}
int main(){
	scanf("%d", &n);
	int i, c1 = 0, c2 = 0, ansp;
	LL ans = n * LL(n + 1) / 2 + 1, sum = 0LL;
	for(i = 1; i <= n; ++ i){
		scanf("%d", &p[i]);
		if(p[i] < i){
			//i,i+1,...,n
			add(i - p[i], 1, n - i + 1);
			//1,2,..,p[i]
			addRev(p[i] - 1, n - i + 2, n - i + p[i] + 1);
			//p[i]+1,p[i]+2,..,i-1
			add(1, n - i + p[i] + 2, n);
		}else{
			//i,..,p[i]
			addRev(p[i] - i, 1, p[i] - i + 1);
			//p[i]+1,..,n
			add(1, p[i] - i + 2, n - i + 1);
			//1,..,i-1
			addRev(p[i] - 1, n - i + 2, n);
		}
	}
	for(i = 1; i <= n; ++ i){
		sum += c1;
		c1 += cnt[i];
		sum += tot[i];

		sum -= c2;
		c2 += cnt2[i];
		sum += tot2[i];

		if(sum < ans) ans = sum, ansp = i - 1;
		
		c1 -= cnt_[i];
		sum -= tot_[i];

		c2 -= cnt2_[i];
		sum -= tot2_[i];
	} printf("%I64d %d\n", ans, ansp);
	return 0;
}