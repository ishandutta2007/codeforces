#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 10010;
int n, a[N], ans = 0;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) 
		scanf("%d", a + i);
		
	int tot = 1;
	while(tot <= n){
		ans++;
		int i = tot;
		tot = max(tot, a[tot]);
		while(++i <= tot){
			tot = max(tot, a[i]);
		}
		tot++;
	} 
	printf("%d\n", ans);
	return 0;
}