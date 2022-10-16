#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 505;
int n, m, K;
int cost[N][N], f[N];
char s[N][N]; 
vector<int> g[N]; 
int inline work(int i, int j) {
	if(j >= g[i].size()) return 0;
	int res = 1e9;
	for(int k = 0; k <= j; k++)
		res = min(res, g[i][(int)g[i].size() - 1 - (j - k)] - g[i][k] + 1);
	return res;
}
int main(){
	memset(f, 0x3f, sizeof f);
	scanf("%d%d%d", &n, &m, &K);
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1); 
		for(int j = 1; j <= m; j++) {
			if(s[i][j] == '1')
				g[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			cost[i][j] = work(i, j);
		} 
	} 
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		for(int j = K; ~j; j--) {
			int val = 1e9;
			for(int k = 0; k <= min(j, m); k++)
				val = min(val, f[j - k] + cost[i][k]);
			f[j] = val;
		}
	}
	int res = 1e9;
	for (int i = 0; i <= K; i++) {
		res = min(res, f[i]);
	}
	printf("%d\n", res);
    return 0;
}