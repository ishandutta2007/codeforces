#include <cstdio>
#include <iostream>
#include <cmath> 
using namespace std;
const int N = 100010;
int n, a[N], val = -1, res = -1; 
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		val = max(val, a[i]);
	}
	int len = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == val) len ++;
		else len = 0;
		res = max(res, len);
	}
	printf("%d\n", res);
	return 0;
}