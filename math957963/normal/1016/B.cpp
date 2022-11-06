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
#define N 10000


int main(){
	char a[N + 1];
	char b[N + 1];
	int c[N + 1];
	f(i, N + 1){
		a[i] = 0;
		b[i] = 0;
	}
	int n, m, q;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d %d", &n, &m, &q);
	scanf("%s", a);
	scanf("%s", b);
	c[0] = 0;

	f(i, n-m+1){
		v = true;
		f(j, m){
			if (a[i + j] != b[j])v = false;
		}
		if (v)c[i + 1] = c[i] + 1;
		else c[i + 1] = c[i];
	}

	f(i, q){
		scanf("%d %d", &x, &y);
		if ((x + m) <= (y + 1))printf("%d\n", c[y - m + 1] - c[x - 1]);
		else printf("0\n");
	}

	return 0;
}