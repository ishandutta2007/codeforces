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
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 100


int main(){
	int l = 0;
	int r, m;
	char c[N + 1];
	char c2[N + 1];
	f(i, N + 1){
		c[i] = 0;
		c2[i] = 0;
	}
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	s = 1 << (n - 1);
	if (n == 1){
		printf("0 0\n");
		fflush(stdout);
		scanf("%s", c);
		printf("1 0 1 1\n");
		fflush(stdout);
		return 0;
	}
	printf("0 0\n");
	fflush(stdout);
	scanf("%s", c);
	printf("%d 0\n",s);
	fflush(stdout);
	scanf("%s", c2);
	l = 0;
	r = r = 1 << (n - 1);
	k = n - 2;
	if (c[0] != c2[0]){
		f(i, n - 2){
			m = (l + r) / 2;
			printf("%d %d\n", m, s - m);
			fflush(stdout);
			scanf("%s", c2);
			if (c[0] == c2[0])l += (1 << k);
			else r -= (1 << k);
			k--;
		}
		m = (l + r) / 2;
		printf("%d %d %d %d\n", m, 0, m, 1);
		fflush(stdout);
	}
	else{
		f(i, n - 2){
			m = (l + r) / 2;
			printf("%d %d\n", s - m, m);
			fflush(stdout);
			scanf("%s", c2);
			if (c[0] == c2[0])l += (1 << k);
			else r -= (1 << k);
			k--;
		}
		m = (l + r) / 2;
		printf("%d %d %d %d\n", 0, m, 1, m);
		fflush(stdout);
	}



	return 0;
}