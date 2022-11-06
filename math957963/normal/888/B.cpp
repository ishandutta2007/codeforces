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
	char a[100000];
	f(i, 100000)a[i] = 0;
	int k, s;
	int n, m;
	int b[4];
	f(i, 4)b[i] = 0;
	int ans = 0;
	scanf("%d", &n);
	scanf("%s", a);
	f(i, n){
		if (a[i] == 'U')b[0]++;
		else if (a[i] == 'D')b[1]++;
		else if (a[i] == 'L')b[2]++;
		else  b[3]++;
	}

	ans += min(b[0], b[1]) * 2;
	ans += min(b[2], b[3]) * 2;

	printf("%d\n", ans);
	return 0;
}