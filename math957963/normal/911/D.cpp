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

int n;
int bit[1501];

int sum(int i){
	int s = 0;
	while (i <= n){
		s += bit[i];
		i += i&-i;
	}

	return s;
}

void add(int i,int x){
	while (i >0){
		bit[i] += x;
		i -= i&-i;
	}
	return;
}

int main(void){
	int a[1500];
	int m;
	int x, y, z;
	int ans = 0;

	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
	}
	f(i, n + 1)bit[i] = 0;
	ans = 0;
	f(i, n){
		ans += sum(a[i]);
		add(a[i], 1);
	}
	scanf("%d", &m);
	f(i, m){
		scanf("%d %d", &x, &y);
		z = (y - x);
		z = (z*(z + 1)) / 2;
		ans = (ans + z) % 2;
		if (ans%2==0)printf("even\n");
		else printf("odd\n");
	}

	return 0;
}