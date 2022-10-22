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
const int N = 1e5 + 10;
int n, m;
int vis[N];
int main() {
	int T;
	for(scanf("%d", &T); T--; ) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) vis[i] = 0;
		for(int i = 1, a, b, c; i <= m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			vis[b] = 1;
		}
		int rt = -1;
		for(int i = 1; i <= n; i++) if(!vis[i]) rt = i;
		for(int i = 1; i <= n; i++) {
			if(i != rt) {
				printf("%d %d\n", i, rt);
			}
		}
	}
    return 0;
}