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
	long long p[20];
	long long k;
	long long n, m;
	long long x, y, w;
	long long ans = 0;
	long long c = 0;

	scanf("%I64d %I64d", &n, &m);
	p[0] = 1;
	for (int i = 1; i < 20; i++){
		p[i] = p[i - 1] * 10;
		p[i] = p[i] % m;
	}
	k = 1;
	while (c<n){
		x = k;
		w = -1;
		while (x != 0){
			w++;
			x = x / 10;
		}
		x = k;
		y = 0;
		while (x != 0){
			ans += (p[w-y] + p[w + y+1])*(x % 10);
			ans = ans%m;
			x = x / 10;
			y++;
		}
		c++;
		k++;
	}

	printf("%I64d\n", ans);

	return 0;
}