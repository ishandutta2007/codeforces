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
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200100


int main(){
	vector<long long>a;
	vector<long long>b;
	long long c[100];
	long long d[100];
	long long re[100];
	long long n;
	long long k;
	long long x;
	f(i, 100){
		if (i > 0){
			x = MOD - 2;
			c[0] = i;
			f(j, 99)c[j + 1] = (c[j] * c[j]) % MOD;
			re[i] = 1;
			f(j, 100){
				if (x % 2 == 1)re[i] = (re[i] * c[j]) % MOD;
				x = x / 2;
			}
		}
	}
	scanf("%I64d", &n);
	scanf("%I64d", &k);
	for (long long i = 2;; i++){
		if (n == 1)break;
		if (i*i > n)break;
		if (n%i == 0){
			x = 0;
			while (n%i == 0){
				n = n / i;
				x++;
			}
			a.push_back(i);
			b.push_back(x);
		}
	}
	if (n > 1){
		a.push_back(n);
		b.push_back(1);
	}
	long long ans = 1;
	long long s;
	f(i, a.size()){
		s = 0;
		f(j, 100)c[j] = 0;
		c[b[i]] = 1;
		f(j, k){
			f(ii, b[i] + 1)d[ii] = 0;
			f(ii, b[i] + 1){
				x = (c[ii] * re[ii + 1]) % MOD;
				f(jj, ii+1){
					d[jj] = (d[jj] + x) % MOD;
				}
			}
			f(ii, b[i] + 1)c[ii] = d[ii];
		}
		x = 1;
		f(j, b[i] + 1){
			s =(s + (x*c[j])) % MOD;
			x = (x*a[i]) % MOD;
		}
		ans = (ans*s) % MOD;
	}

	printf("%I64d\n", ans);


	return 0;
}