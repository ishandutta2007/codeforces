#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 5010;
int n, m, sum[N], c[N], c2[N], tot = 0, ans = -1;
PII a[N]; 
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &a[i].first, &a[i].second);
		
	}
	sort(a + 1, a + 1 + m);
	for(int i = 1; i <= m; i++){
		sum[a[i].first]++, sum[a[i].second + 1]--;
	}
	for(int i = 1; i <= n; i++) {
		sum[i] += sum[i - 1];
		c[i] = c[i - 1] + (sum[i] == 1);
		c2[i] = c2[i - 1] + (sum[i] == 2);
		tot += (sum[i] > 0);
	}
	for(int i = 1; i < m; i++){
		for(int j = i + 1; j <= m; j++){
			int cnt = tot;
			int L = a[i].first, R = a[i].second;
			int L1 = a[j].first, R1 = a[j].second;
			if(L1 <= R) {
				cnt -= c[L1 - 1] - c[L - 1];
				cnt -= c[max(R, R1)] - c[min(R, R1)];
				cnt -= c2[min(R, R1)] - c2[L1 - 1];
			}else{
				cnt -= c[R] - c[L - 1];
				cnt -= c[R1] - c[L1 - 1];
			}
			ans = max(ans, cnt);
		}
	}
	printf("%d\n", ans);
	return 0;
}