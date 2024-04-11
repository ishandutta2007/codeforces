#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[110000];
int main(){
	int n, k;
	scanf("%d%d%s", &n, &k, a);
	int c[110000];
	int ans = 0;
	c[0] = 0;
	for(int i = 0; i < n; i++){
		c[i+1] = (a[i] == 'a') + c[i];
	}
	int cur = 0;
	for(int i = 0; i <= n; i++){
		while(c[cur] + k < c[i]){
			cur++;
		}
		ans = max(ans, i-cur);
	}

	for(int i = 0; i < n; i++){
		c[i+1] = (a[i] == 'b') + c[i];
	}
	cur = 0;
	for(int i = 0; i <= n; i++){
		while(c[cur] + k < c[i]){
			cur++;
		}
		ans = max(ans, i-cur);
	}
	printf("%d\n", ans);
}