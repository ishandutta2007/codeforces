# include <iostream>
# include <cstdio>
# include <bitset>

using namespace std;

const int maxn = 120;

char a[maxn][maxn];

bitset<100> c[maxn];

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s", a[i]);
		for(int j = 0; j < n; ++j) 
			if (a[i][j] == '1') c[i].set(j);
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int val = 0;
		for(int j = 0; j < n; ++j) if(c[i] == c[j]) val ++;
		ans = max(ans, val);
	}
	printf("%d\n", ans);
}