#include <cstdio>
#include <iostream>
using namespace std;
const int N = 110;
int n, a[N], ans = 0;
int d[3][3]{
	{-1, 3, 4},
	{3, -1, -1},
	{4, -1, -1}
};
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", a + i);
	
	for(int i = 2; i <= n; i++){
		int res = d[a[i - 1] - 1][a[i] - 1];
		if(i > 1 && i + 1 <= n && a[i + 1] == 2 && a[i] == 1 && a[i - 1] == 3) res = 3;
		if(res == -1){
			puts("Infinite");
			return 0;
		}else{
			ans += res;
		}
	}
	printf("Finite\n%d\n", ans);
	return 0;
}