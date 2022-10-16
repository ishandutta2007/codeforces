#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;


const int MOD = 1000000007,
          MaxN = 1000001;

int n;

int fact[MaxN], pwr2[MaxN];

void get_fact(){
	fact[0] = 1;
	for(int i = 1; i <= n; i++) fact[i] = ((LL)fact[i-1] * i) % MOD;
	//for(int i = 0; i <= n; i++) printf("%d ", fact[i]);
	//printf("\n");
}
void get_pwr2(){
	pwr2[0] = 1;
	for(int i = 1; i <= n; i++) pwr2[i] = (pwr2[i-1]*2) % MOD;
}
int pow_mod(int a, int n){
	if(!n) return 1;
	int val = pow_mod(a,n/2);
	val = ((LL)val*val) % MOD;
	if(n % 2 == 1) val = ((LL)val*a) % MOD;
	return val;
}
int inv_mod(int a){  //mod MOD
	return pow_mod(a, MOD-2);
}
int binom(int n, int k){
	//printf("binom(%d,%d)\n",n,k);
	if(k < 0 || k > n) return 0;
	
	int val = fact[n];
	//printf("IM(%d)=%d\n", fact[n-k], inv_mod(fact[n-k]));
	val = ((LL)val * inv_mod(fact[k])) % MOD;
	val = ((LL)val * inv_mod(fact[n-k])) % MOD;
	//printf("=>%d\n", val);
	return val;
}


int pos[MaxN];

int main(){
	scanf("%d", &n);
	
	get_fact();
	get_pwr2();
	
	for(int i = 0; i < n; i++){
		int v;
		scanf("%d", &v);
		if(v) pos[n-v+1] = i+1;
	}
	
	int n1=0, k1=0, v1=1, n2=0, k2=0, v2=0;
	for(int i = 1; i <= n; i++){
		if(!pos[i]) continue;
		
		int L1 = pos[i], R1 = i-L1, NV1=0,
		    R2 = n-pos[i]+1, L2 = i-R2, NV2=0;
		
		if(R1 >= 0){
			NV1 = ((LL)v1 * binom(i-n1-1, L1-k1-1) +
			       (LL)v2 * binom(i-n2-1, L1-k2-1)) % MOD;
		}
		if(L2 >= 0){
			NV2 = ((LL)v1 * binom(i-n1-1, L2-k1) +
			       (LL)v2 * binom(i-n2-1, L2-k2)) % MOD;
		}
		
		n1 = n2 = i;
		v1 = NV1; v2 = NV2;
		k1 = L1; k2 = L2;
		
		//printf("n1=%d n2=%d k1=%d k2=%d v1=%d v2=%d\n", n1,n2,k1,k2,v1,v2);
	}
	
	int res = ((LL)(v1+v2) * pwr2[n-n1]) % MOD;
	
	printf("%d\n", (int)(((LL)res*inv_mod(2)) % MOD));
}