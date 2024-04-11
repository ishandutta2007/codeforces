#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

typedef long long LL;

int n;

int tbl[1000005];

int main(){
	scanf("%d", &n);
	cout << ((LL)n * (n+1)) << endl;
	
	int pwr = 1;
	while(pwr <= n) pwr <<= 1;
	pwr >>= 1;
	
	int nn = n;
	//printf("nn=%d pwr=%d\n", nn, pwr);
	
	while(pwr){
		for(int i = pwr; i <= nn; i++){
			tbl[i] = 2*pwr-i-1;
			tbl[2*pwr-i-1] = i;
		}
		nn -= (nn-pwr+1)*2;
		if(nn <= 0) break;
		while(pwr > nn) pwr >>= 1;
		//printf("nn=%d pwr=%d\n", nn, pwr);
	}
	
	for(int i = 0; i <= n; i++) printf("%d ", tbl[i]);
	printf("\n");
}