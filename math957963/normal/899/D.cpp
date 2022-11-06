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
#define MOD 1000000009

int main(void){
	long long k, s;
	long long n, m;
	long long x, y, z;
	long long ans = 0;

	scanf("%I64d", &n);
	if (n < 5)ans = n*(n - 1) / 2;
	else{
		s = n * 2;
		s = s / 10;
		k = 1;
		while (s != 0){
			k = k * 10;
			s = s / 10;
		}
		x = n / k;
		y = n % k;
		y++;
		ans = x*x;
		if (y == k){
			ans = ((x+1)*(x+1)*k) / 2;
			ans -= (x + 1);
		}
		else if (y > (k / 2)){
			s = (x + 1)*x*(k - y - 1);
			ans += s;
			s = (x + 1)*(x + 1)*(y - (k / 2));
			ans += s;
		}
		else{
			s = (x + 1)*x*(y - 1);
			ans += s;
			s = x*x*((k / 2) - y);
			ans += s;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}