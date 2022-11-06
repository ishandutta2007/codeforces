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
	int a[1000];
	int b[1000];
	f(i, 1000){
		a[i] = 0;
		b[i] = 0;
	}
	int k, s;
	int n, m;
	int x, y, z;
	int ans = 0;

	scanf("%d", &n);
	f(i, n){
		scanf("%d %d", &a[i],&b[i]);
	}
	k = 0;
	f(i, n){
		k++;
	while(!((k >= a[i]) && (k%b[i] == (a[i] % b[i]))))k++;
	}

	printf("%d\n", k);

	return 0;
}