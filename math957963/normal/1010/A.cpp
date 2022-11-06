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
#define N 20000


int main(){
	vector<long double>a, b, c;
	int n;
	long double x;
	long double s, ans;
	scanf("%d", &n);
	scanf("%Lf", &s);
	ans = s;
	f(i, n){
		scanf("%Lf", &x);
		b.push_back(x);
	}
	f(i, n){
		scanf("%Lf", &x);
		c.push_back(x);
	}
	a.push_back(c[0]);
	f(i, n - 1){
		a.push_back(b[n-i-1]);
		a.push_back(c[n-i-1]);
	}
	a.push_back(b[0]);

	f(i, 2*n){
		if (a[i] < 1.5){
			printf("-1\n");
			return 0;
		}
		ans = (a[i] / (a[i] - 1))*ans;
	}
	ans -= s;

	printf("%.10Lf\n", ans);


	return 0;
}