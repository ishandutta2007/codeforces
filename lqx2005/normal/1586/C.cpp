#include<bits/stdc++.h>
   
using namespace std;
   
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define sz(a) int((a).size())
#define x first
#define y second
#define mp make_pair

typedef long long i64;
typedef unsigned long long u64;
typedef double db; 
const int N = 1e6 + 10;
int n, m, q, sum[N];
vector<int> a[N];
char s[N];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		a[i].resize(m + 1);
		scanf("%s", s + 1);
		for(int j = 1; j <= m; j++) {
			a[i][j] = s[j] == 'X';
		}
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j < m; j++) {
			if(a[i][j] && a[i - 1][j + 1]) {
				sum[j]++;
			}
		}
	}
	for(int i = 1; i <= m; i++) sum[i] += sum[i - 1];
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if(l == r) puts("YES");
		else {
			puts(sum[r - 1] - sum[l - 1] == 0 ? "YES" : "NO");
		}
	}
    return 0;
}