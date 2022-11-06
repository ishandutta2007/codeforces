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
#define N 1000100


int main() {
	char a[N];
	f(i, N)a[i] = 0;
	long long n;
	long long t;
	long long x, y, z;
	long long s, ans, k;
	bool v = true;
	f(i, N)a[i] = 0;
	scanf("%I64d", &t);
	f(tt, t) {
		ans = 0;
		scanf("%I64d", &n);
		scanf("%s", a);
		k = strlen(a);
		if (k >= n)v = false;
		else v = true;
		f(i, n) {
			if (a[i] == '2') {
				for (long long j = i + 1; j < k; j++) {
					if(v&&((k+j-i-1)<n))a[k + j - i - 1] = a[j];
					else {
						v = false;
						break;
					}
				}
				k = (k + (k - i - 1)+MOD) % MOD;
			}
			if (a[i] == '3') {
				for (long long j = i + 1; j < k; j++) {
					if (v && ((k + j - i - 1) < n))a[k + j - i - 1] = a[j];
					else {
						v = false;
						break;
					}
				}
				for (long long j = i + 1; j < k; j++) {
					if (v&&((k + j - i - 1+k-i-1) < n))a[k + j - i - 1 + k - i - 1] = a[j];
					else {
						v = false;
						break;
					}
				}
				k = (k + (k - i - 1) + (k - i - 1)+MOD+MOD) % MOD;
			}


		}
		printf("%I64d\n", k);
		n = strlen(a);
		f(i, n + 1)a[i] = 0;
	}



	return 0;
}