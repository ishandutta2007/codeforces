#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
bool ff[maxn][maxn][maxn * maxn >> 1];
bool vis[maxn][maxn][maxn * maxn >> 1];
int f(int n, int m, int k){
	if(vis[n][m][k]) return ff[n][m][k];
	vis[n][m][k] = 1;
	if(n == 0 || m == 0) return ff[n][m][k] = 1;
	ff[n][m][k] = 0;
	if(m % 2 == 0 && m <= k * 2) ff[n][m][k] |= f(n - 1, m, k - (m >> 1));
	if(n % 2 == 0 && n <= (n * m / 2 - k) * 2) ff[n][m][k] |= f(n, m - 1, k);
	return ff[n][m][k];
}// n*mk

int t,n,m,k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		if(f(n, m, k)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}