#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

char str[1000005];
int n, k;

int main(){
	scanf("%d%d", &n, &k);
	if(k > n){ printf("-1\n"); return 0; }
	if(k == 1){
		if(n == 1) printf("a\n"); else printf("-1\n");
		return 0;
	}
	if(n == k){
		for(int i = 0; i < n; i++) printf("%c", i+'a');
		printf("\n");
		return 0;
	}
	for(int i = 0; i < n-k+2; i++) putc(i%2==0 ? 'a' : 'b', stdout);
	for(int i = 2; i < k; i++) putc('a'+i, stdout);
	printf("\n");
}