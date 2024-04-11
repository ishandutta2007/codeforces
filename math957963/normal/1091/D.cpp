#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 998244353
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000

int main(){
	long long n;
	long long x, y, z;
	long long s, ans;
	scanf("%I64d", &n);
	s = 1;
	ans = 0;
	for (long long i = 1; i <= n - 2; i++){
		s *= (n - i + 1);
		s %= MOD;
		x = i*s;
		x %= MOD;
		x *= (n - i - 1);
		x %= MOD;
		ans += x;
		ans %= MOD;
	}
	s = 1;
	f(i, n){
		s *= (i + 1);
		s %= MOD;
	}
	ans += s;
	ans %= MOD;

	printf("%I64d\n", ans);


	return 0;
}