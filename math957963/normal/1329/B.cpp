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
#define N 200000


int main() {
	long long a[N];
	a[0] = 1;
	f(i, 30)a[i + 1] = a[i] * 2;
	long long n, k, t;
	long long s, ans;
	scanf("%lld", &t);
	f(tt, t) {
		scanf("%lld %lld", &n, &k);
ans=1%k;
		f(i, 30) {
			if (n >= a[i]) {
				if (n < a[i + 1]){
					ans = (ans * (n - a[i] + 2)) % k;
					break;
					}
				else {
					ans = (ans * (a[i] + 1)) % k;
				}
			}
			else break;
		}
		ans = (ans + k - 1) % k;
		printf("%lld\n", ans);
	}

	return 0;
}