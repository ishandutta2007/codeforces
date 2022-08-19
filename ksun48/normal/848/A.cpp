#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	printf("z");
	char d = 'a';
	while(n > 0){
		int k = 1;
		while(k*(k+1)/2 <= n){
			k++;
		}
		n -= k*(k-1)/2;
		for(int j = 0; j < k; j++){
			printf("%c", d);
		}
		d++;
	}
	printf("\n");
}