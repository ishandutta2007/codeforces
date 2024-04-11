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
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<long long(n);i++)
#define N 300000


int main(){
	long long a[N];
	long long b[N];
	long long c[N + 1];
	long long d[N + 1];
	f(i, N){
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
		d[i] = 0;
	}
	c[N] = 0;
	d[N] = 0;
	long long n;
	long long ans;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	f(i, n){
		scanf("%I64d", &a[i]);
	}
	f(i, n){
		scanf("%I64d", &b[i]);
	}
	c[n] = 0;
	f(i, n){
		c[n - i - 1] = c[n - i] + a[n - i - 1] + b[n - i - 1];
	}
	f(i, n){
		d[0] += (i*a[i]);
		d[0] += (((2 * n) - i - 1)*b[i]);
	}
	if (n > 1){
		d[1] += b[0];
		f(i, n-1){
			d[1] += (((2 * n) - i - 1)* a[i + 1]);
			d[1] += ((i+2)*b[i+1]);
		}
	}
	ans = 0;
	for (long long i = 2; i < n; i++){
		d[i] = d[i - 2];
		if (i % 2 == 0){
			d[i] -= (2 * (n - i + 1)*b[i - 2]);
			d[i] -= (2 * (n - i)*b[i - 1]);
			d[i] += (2 * a[i - 1]);
			d[i] += (2*c[i]);
		}
		else {
			d[i] -= (2 * (n - i + 1)*a[i - 2]);
			d[i] -= (2 * (n - i)*a[i - 1]);
			d[i] += (2 * b[i - 1]);
			d[i] += (2*c[i]);
		}
	}
	f(i, n){
		ans = max(ans, d[i]);
	}


	printf("%I64d\n", ans);


	return 0;
}