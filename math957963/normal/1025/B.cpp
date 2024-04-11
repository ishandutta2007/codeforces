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

long long gc(long long x, long long y){
	if (x > y)swap(x, y);
	if (x == 0)return y;
	y = y%x;
	return gc(y, x);
}


int main(){
	long long a[N];
	f(i, N)a[i] = 0;
	int n;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n){
		scanf("%I64d %I64d", &x,&y);
		a[i] = x*y;
	}
	if (n == 1){
		printf("%I64d\n", x);
		return 0;
	}
	ans = gc(a[0], a[1]);
	f(i, n-2){
		ans = gc(ans, a[i + 2]);
	}
	if (ans == 1){
		printf("-1\n");
		return 0;
	}
	z = 2;
	while (x > 1){
		if (z > 100000){
			if (ans%x == 0){
				printf("%I64d\n", x);
				return 0;
			}
			x = 1;
		}
		else if (x%z == 0){
			if (ans%z == 0){
				printf("%I64d\n", z);
				return 0;
			}
			x = x / z;
		}
		else z++;
	}

	z = 2;
	while (y > 1){
		if (z > 100000){
			if (ans%y == 0){
				printf("%I64d\n", y);
				return 0;
			}
			y = 1;
		}
		else if (y%z == 0){
			if (ans%z == 0){
				printf("%I64d\n", z);
				return 0;
			}
			y = y / z;
		}
		else z++;
	}

	return 0;
}