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
int pa[100000];
long long m[100000];

int find(int x){
	if (pa[x] == x)return x;
	else return pa[x] = find(pa[x]);
}
//
//01
int main(void){
	f(i, 100000)pa[i] = i;
	int q;
	int n;
	int x, y;
	long long ans = 0;

	scanf("%d %d", &n, &q);
	f(i, n){
		scanf("%I64d", &m[i]);
	}


	f(qq, q){
			scanf("%d %d", &x, &y);
			x = find(x - 1);
			y = find(y - 1);
			if (x > y)swap(x, y);
			pa[y] = x;
			m[x] = min(m[x], m[y]);
	}
	f(i, n){
		if (pa[i] == i)ans += m[i];
	}
	printf("%I64d\n", ans);

	return 0;
}