#include <cstdio>

char ans[(1 << 10) + 5][(1 << 10) + 5];

void solve(int x){
	if(x == 1){
		ans[1][1] = ans[2][2] = ans[1][2] = '*';
		ans[2][1] = '+';
		return;
	}
	solve(x - 1);
	int i, j;
	for(i = 1; i <= (1 << (x - 1)); ++ i)
		for(j = 1; j <= (1 << (x - 1)); ++ j){
			ans[i][j + (1 << (x - 1))] = ans[i][j];
			ans[i + (1 << (x - 1))][j] = ans[i][j];
		}
	for(i = 1; i <= (1 << (x - 1)); ++ i)
		for(j = 1; j <= (1 << (x - 1)); ++ j)
			ans[i + (1 << (x - 1))][j + (1 << (x - 1))] = (ans[i][j] == '*' ? '+' : '*');
}
int main(){
	int i, k;
	scanf("%d", &k);
	if(k == 0){
		printf("*\n");
		return 0;
	}
	solve(k);
	for(i = 1; i <= (1 << k); ++ i)
		printf("%s\n", ans[i] + 1);
	return 0;
}