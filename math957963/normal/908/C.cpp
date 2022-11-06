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
	double a[1000];
	f(i, 1000)a[i] = 0;
	double x[1000];
	double k, s;
	int n;
	double r;
	double y, z;
	int ans = 0;

	scanf("%d %lf", &n,&r);
	f(i, n){
		scanf("%lf", &a[i]);
	}

	f(i, n){
		y = r;
		f(j, i){
			k = fabs(a[i] - a[j]);
			if (k<= 2 * r + 0.1){
				z = (4 * r*r) - (k*k)+0.0000000000000000001;
				z = sqrt(z);
				y = max(y, x[j] + z);
			}
		}
		x[i] = y;
		printf("%f", x[i]);
		if (i < n - 1)printf(" ");
		else printf("\n");
	}

	return 0;
}