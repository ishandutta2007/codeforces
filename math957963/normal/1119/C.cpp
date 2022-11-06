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
#define N 600


int main() {
	int a;
	int x[N];
	int y[N];
	int xx[N];
	int yy[N];
	bool v = true;
	int n,m;
	f(i, N) {
		x[i] = 0;
		y[i] = 0;
		xx[i] = 0;
		yy[i] = 0;
	}
	scanf("%d %d", &n,&m);
	f(i, n) {
		f(j, m) {
			scanf("%d", &a);
			x[i] += a;
			y[j] += a;

		}
	}
	f(i, n) {
		f(j, m) {
			scanf("%d", &a);
			xx[i] += a;
			yy[j] += a;

		}
	}
	f(i, n) {
		if ((x[i] % 2) != (xx[i] % 2))v = false;
	}
  f(i,m){
    		if ((y[i] % 2) != (yy[i] % 2))v = false;
  }

	if (v)printf("Yes\n");
	else printf("No\n");
	return 0;
}