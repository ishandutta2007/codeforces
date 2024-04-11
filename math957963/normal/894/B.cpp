#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000007

long long pow(long long n){
	long long b[60];
	long long ans;
	b[0] = 2;
	ans = 1;
	for (int i = 1; i < 60; i++){
		b[i] = b[i - 1] * b[i - 1];
		b[i] = b[i] % MOD;
	}
	for (int i = 0; i < 60; i++){
		if (n % 2 == 1){
			ans = ans*b[i];
			ans = ans%MOD;
		}
		n = n / 2;
	}
	return ans;
}

int main(void){
	long long k, s;
	long long n, m;
	long long ans = 1;

	scanf("%I64d %I64d %I64d", &n,&m,&k);

	if (n % 2 == 0 && m % 2 == 1&&k==-1)printf("0\n");
	else if (m % 2 == 0 && n % 2 == 1&&k==-1)printf("0\n");
	else{
		n = (n - 1) % (MOD - 1);
		m = (m - 1) % (MOD - 1);
		n = (n*m) % (MOD - 1);
		if(n>0)ans = pow(n);
		ans = ans%MOD;
		printf("%I64d\n", ans);
	}
	return 0;
}