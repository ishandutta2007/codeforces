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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 300010


int main(){
	int a[N];
	long long b0[N+2];
	long long b1[N+2];
	int c[N + 1];
	int n, k, s,m;
	long long x, y, z, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	k = 0;
	b0[0] = 0;
	b1[0] = 0;
	b0[1] = 1;
	b1[1] = 0;
	f(i, n){
		scanf("%I64d", &x);
		s = 0;
		while (x > 0){
			if (x % 2 == 1)s++;
			x = x / 2;
		}
		a[i] = s;
		c[i] = k;
		if (s % 2 == 1)k = (k + 1) % 2;
		if (k % 2 == 1){
			b1[i + 2] = b1[i+1] + 1;
			b0[i + 2] = b0[i+1];
		}
		else{
			b0[i + 2] = b0[i+1] + 1;
			b1[i + 2] = b1[i+1];
		}
	}
	f(i, n){
		s = 0;
		m = a[i];
	for (int j = 0; j < 61; j++){
			if (i + j >= n)break;
			m = max(m, a[i + j]);
			s += a[i + j];
			if ((2 * m) <= s&&s % 2 == 0){
				ans++;
			}
		}
		if (i + 61 < n){
			if (c[i] == 0){
				z = b0[n + 1] - b0[i + 62];
			}
			else{
				z = b1[n + 1] - b1[i + 62];
			}
			ans += z;
		}

	}

	printf("%I64d\n", ans);


	return 0;
}