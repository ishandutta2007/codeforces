#include <cstdio>
#include <iostream>
using namespace std;
const int N = 200005;
int n, a[N], cnt = 0; 
int main(){
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if(a[i]) continue;
		++cnt;
		for (int j = i; j <= n; j += i)
			a[j] = cnt;
	}
	
	for (int i = 2; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}