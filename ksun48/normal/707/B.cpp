#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int ans = 1100000000;
int ok[110000];
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int u[m], v[m], l[m];
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &u[i], &v[i], &l[i]);
	}
	for(int i = 0; i < n; i++) ok[i] = 0;
	for(int i = 0; i < k; i++){
		int a;
		scanf("%d", &a);
		ok[a] = 1;
	}
	for(int i = 0; i < m; i++){
		if(ok[u[i]] != ok[v[i]]) ans = min(ans, l[i]);
	}
	if(ans == 1100000000){
		printf("%d\n", -1);
	} else {
		printf("%d\n", ans);
	}
}