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
#define N 400000


int main(){
	long long a[N];
	int b[N];
	long long c[N];
	bool d[N];
	f(i, N){
		c[i] = -1;
		d[i] = false;
	}
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %I64d", &n, &s);
	f(i, n){
		scanf("%I64d", &a[i]);
	}
	k = 0;
	f(i, n){
		scanf("%d", &b[i]);
		b[i]--;
		for (int j = max(k, i + 1); j <= b[i]; j++){
			d[j] = true;
		}
		k = b[i] + 1;
		if (b[i] < i)v = false;
		if (i > 0){
			if (b[i - 1] > b[i])v = false;
		}
		if (b[i] < n - 1)c[b[i]] = a[b[i] + 1] + s - 1;
	}

	c[n-1] = 3000000000000000000;
	f(i, n - 1){
		if (c[n - i - 2] == -1){
			c[n - i - 2] = c[n - i - 1] - 1;
		}
	}
	f(i, n){
		if (d[i]){
			if (c[i - 1] < a[i] + s)v = false;
		}
	}

	if (v){
		printf("Yes\n");
		f(i, n){
			printf("%I64d", c[i]);
			if (i < n - 1)printf(" ");
			else printf("\n");
		}
	}
	else printf("No\n");

	return 0;
}