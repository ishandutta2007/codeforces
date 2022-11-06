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
#define N 200000


int main(){
	long double x[N];
	long double y[N];
	long double l, r, m, ll, rr, xx;
	int n, k;
	scanf("%d", &n);
	f(i, n){
		scanf("%Lf %Lf", &x[i], &y[i]);
		if (y[0] < 0){
			if (y[i] > 0){
				printf("-1\n");
				return 0;
			}
		}
		else{
			if (y[i] < 0){
				printf("-1\n");
				return 0;
			}
		}
	}
	if (y[0] < 0){
		f(i, n)y[i] = -y[i];
	}
	l = 0;
	r = 1000000000000000;
	while (l + 0.0000001 < r){
		m = (l + r) / 2;
		ll = -10000000000000000;
		rr = 10000000000000000;

		f(i, n){
			xx = (2 * m) - y[i];
			xx = xx*y[i];
			if (xx < 0){
				xx = 0;
				ll = rr + 1;
			}
			else xx = sqrtl(xx);
			ll = max(ll, (x[i] - xx));
			rr = min(rr, (x[i] + xx));
		}
		if (ll <= rr)r = m;
		else l = m;
		if ((r - l) < (0.000000001*l))break;
	}


	printf("%Lf\n", r);


	return 0;
}