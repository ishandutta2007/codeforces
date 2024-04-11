#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

const int Mod = 1000000007;

int n, k;

/*bool use[10];
int ptr[10];

int check(){
	for(int i = 1; i <= k; i++) printf("%d ", ptr[i]);
	printf("\n");
	int p = 1, s = 0;
	for(; s < k; s++){
		p = ptr[p];
		
		printf("[%d:%d]\n", p, s);
		if(p == 1) return 1;
	}
	return 0;
}

int get_k(int i){
	if(i == k){
		return check();
	}
	int sum = 0;
	for(int j = 1; j <= k; j++){
		//if(use[j]) continue;
		ptr[i+1] = j; use[j] = true;
		sum += get_k(i+1);
		use[j] = false;
	}
	return sum;
}*/

int pow_mod(int a, int p, int m){
	if(!p) return 1;
	long long tmp;
	tmp = pow_mod(a, p/2, m);
	tmp = (tmp*tmp)%m;
	if(p % 2 == 1) tmp = (tmp*a)%m;
	return tmp;
}

int main(){
	scanf("%d%d", &n, &k);
	//printf("%d\n", get_k(0));
	
	printf("%d\n", ((long long)pow_mod(k,k-1,Mod) * pow_mod(n-k, n-k, Mod))%Mod);
}