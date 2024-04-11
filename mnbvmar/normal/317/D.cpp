#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int data[30] = {
0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12
};


int N;
int Bound;

set<int> bigPowers;


void input(){
	scanf("%d", &N);
}


LL mkpow(LL a, LL n){
	if(!n) return 1;
	LL res = mkpow(a, n/2);
	res *= res;
	if(n % 2 == 1) res *= a;
	return res;
}

bool is_power(int N){
	for(int pwr = 2; (1<<pwr) <= N; pwr++){
		LL what = (LL)lround(powl(N, 1./pwr));

		if(mkpow(what-1, pwr) == N ||
				mkpow(what, pwr) == N ||
				mkpow(what+1, pwr) == N)
			return true;
	}
	return false;
}

int highest_power(int a){
	int result = 1;
	LL what = a;
	while(what*a <= N){
		what *= a;
		result++;

		if(what >= Bound) bigPowers.insert(what);
	}
	return result;
}


int main(){
	input();
	int result = 0;
	
	Bound = 1;
	while(Bound*Bound <= N) Bound++;

	for(int k = 1; k*k <= N; k++){
		if(k == 1){
			result ^= data[1];
//			printf("1: 1\n");
			continue;
		}
		if(is_power(k)) continue;
		result ^= data[highest_power(k)];
//		printf("%d: %d\n", k, highest_power(k));
	}

	if((N-Bound+1-bigPowers.size()) % 2 == 1){
//		printf("A\n");
		result ^= data[1];
	}

	printf(result == 0 ? "Petya\n" : "Vasya\n");

//	printf("num not big powers: %d\n", N-Bound+1-bigPowers.size());
}