#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#include <string>

using namespace std;

const int MaxN = 1000005;

int n, k;

void input(){
	scanf("%d%d", &n, &k);
}


int main(){
	input();
	
	if(n == 1){
		if(k == 0)
			printf("1\n");
		else
			printf("-1\n");
	} else {
		if(k < n/2)
			printf("-1\n");
		else {
			int rest = k-n/2+1;
			
			int max = 1000000000;
			int w = max/rest;
			printf("%d %d", (w-1)*rest, w*rest);
			
			for(int i = 1; i < n-1; i++) printf(" %d", i);
			printf("\n");
		}
	}
}