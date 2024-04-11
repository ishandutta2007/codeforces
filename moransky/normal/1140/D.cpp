#include <cstdio>
#include <iostream>
using namespace std;
int n, res = 0;
int main(){
	scanf("%d", &n);
	for(int i = 2; i < n; i++) 
		res += i * (i + 1);
	printf("%d\n", res);
	return 0;
}