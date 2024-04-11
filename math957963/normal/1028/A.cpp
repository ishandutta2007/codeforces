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
#define N 120


int main(){
	char a[N][N];
	f(i, N){
		f(j, N)a[i][j] = 0;
	}
	int n, m;
	int x, y, xx,yy;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &m);
	f(i, n){
		scanf("%s", a[i]);
	}
	x = n;
	y = 0;
	xx = m;
	y = 0;
	f(i, n){
		f(j, m){
			if (a[i][j] == 'B'){
				if (i < x)x = i;
				if (i > y)y = i;
				if (j < xx)xx = j;
				if (j > yy)yy = j;
			}
		}
	}

	x = (x + y) / 2;
	x++;
	xx = (xx + yy) / 2;
	xx++;

	printf("%d %d\n", x, xx);

	return 0;
}