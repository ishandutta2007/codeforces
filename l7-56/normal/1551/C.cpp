#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, maxl = 4e5 + 10;
int n,T,cnt[maxn][6],ans,d[maxn];
char s[maxl];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	scanf("%d", &T);
	while(T--){
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			cin >> s;
			cnt[i][5] = strlen(s);
			for(int j = 0; j < cnt[i][5]; ++j)
				cnt[i][s[j] - 'a']++;
		}
		ans = 0;
		for(int c = 0; c < 5; ++c){
			for(int i = 1; i <= n; ++i) d[i] = (cnt[i][c] << 1) - cnt[i][5];
			sort(d + 1, d + n + 1, cmp);
			int sum = 0;
			for(int i = 1; i <= n; ++i) {
				sum += d[i];
				if(sum > 0) ans = max(ans, i);
				else break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}