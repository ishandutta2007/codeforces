#include <bits/stdc++.h>
using namespace std;
const int MAXL = 2000005;

int n, m, cnt, f[MAXL], pos[MAXL]; char str[MAXL], ans[MAXL];

int find(int x){return f[x] < 0 ? x : (f[x] = find(f[x]));}
void merge(int u, int v){
	u = find(u), v = find(v);
	if(f[u] > f[v]) f[v] += f[u], f[u] = v;
	else f[u] += f[v], f[v] = u, pos[u] = pos[v];
}
int main(){
	int i, j, mx = 0;
	for(i = 1; i <= 2000000; ++ i)
		f[i] = -1, pos[i] = i;
	scanf("%d", &n);
	while(n --){
		scanf("%s%d", str, &cnt);
		m = strlen(str);
		while(cnt --){
			scanf("%d", &i);
			mx = max(mx, i + m - 1);
			for(j = pos[find(i)]; j < i + m; j = pos[find(j)]){
				ans[j] = str[j - i];
				merge(j, j + 1);
			}
		}
	}
	for(i = 1; i <= mx; ++ i)
		putchar(ans[i] ? ans[i] : 'a');
	return 0;
}