#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

int ans[100005][4];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	if(m > 3){
		puts("YES");
		for(int i = 1; i <= n; ++i, puts("")){
			if(i & 1){
				if(m > 4){
					for(int j = 1; j <= m; j += 2) printf("%d ", (i - 1) * m + j);
					for(int j = 2; j <= m; j += 2) printf("%d ", (i - 1) * m + j);
				}else{
					int base = (i - 1) * m;
					printf("%d %d %d %d", base + 3, base + 1, base + 4, base + 2);
				}
			}else{
				for(int j = 2; j <= m; j += 2) printf("%d ", (i - 1) * m + j);
				for(int j = 1; j <= m; j += 2) printf("%d ", (i - 1) * m + j);
			}
		}
	}else if(n > 3){
		for(int j = 1; j <= m; ++j){
			if(j & 1){
				int cnt = 0;				
				for(int i = 1; i <= n; i += 2) ans[++cnt][j] = (i - 1) * m + j;
				for(int i = 2; i <= n; i += 2) ans[++cnt][j] = (i - 1) * m + j;
				if(n == 4) swap(ans[1][j], ans[2][j]), swap(ans[3][j], ans[4][j]);
			}else{
				int cnt = 0;
				for(int i = 2; i <= n; i += 2) ans[++cnt][j] = (i - 1) * m + j;
				for(int i = 1; i <= n; i += 2) ans[++cnt][j] = (i - 1) * m + j;
			}
		}
		puts("YES");
		for(int i = 1; i <= n; ++i, puts(""))
			for(int j = 1; j <= m; ++j)
				printf("%d ", ans[i][j]);
	}else{
		if(n == 1 && m == 1){
			puts("YES");
			puts("1");
		}else if(n == 3 && m == 3){
			puts("YES");
			puts("1 3 4");
			puts("5 7 6");
			puts("9 2 8");
		}else puts("NO");
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}