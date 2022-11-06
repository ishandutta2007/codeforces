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
#define MOD (998244353)
#define f(i,n) for(int i=0;i<int(n);i++)
long long p[30];
long long m;
void init(void){
	p[0] = m;
	p[0] = p[0] % MOD;
	f(i,29){
		p[i + 1] = p[i] * p[i];
		p[i + 1] = p[i + 1] % MOD;
	}
	return;
}

long long po(int k){
	long long re = 1;
	int rr = 0;
	while (k > 0){
		if (k % 2 == 1){
			re = re*p[rr];
			re = re%MOD;
		}
		rr++;
		k = k / 2;
	}
	return re;
}


int main(){
	int  n, k;
	int x, y, z;
	long long s, ans;
	ans = 1;
	scanf("%d %d %I64d", &n, &k, &m);
	init();
	x = 0;
	f(i, k){
		scanf("%d", &y);
		z = y - x;
		s = po(z);
		s = s*(s + 1);
		s = s / 2;
		s = s%MOD;
		ans = ans*s;
		ans = ans%MOD;
		x = y;
	}
	z = n - (2 * x);
	s = po(z);
	ans = ans*s;
	ans = ans%MOD;
	printf("%I64d\n", ans);


	return 0;
}