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
	char a[100001];
	f(i, 100001)a[i] = 0;
	int k, s;
	int n, m;
	int max[26];
	int last[26];
	f(i, 26){
		max[i] = 0;
		last[i] = -1;
	}
	int ans = 10000000;
	scanf("%s", a);
	n = strlen(a);
	f(i, n){
		k = a[i] - 97;
		if (i - last[k] > max[k])max[k] = i - last[k];
		last[k] = i;
	}
	f(i, 26){
		if (n - last[i] > max[i])max[i] = n - last[i];
		ans = min(ans, max[i]);
	}
	printf("%d\n", ans);

	return 0;
}