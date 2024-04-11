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

int gcd(int x, int y){
	int k;
	if (x > y){
		k = x;
		x = y;
		y = k;
	}
	k = y / x;
	if (y%x == 0)return x;
	else return gcd(y - (k*x), x);
}


int main(void){
	vector<int>a;
	long long s = 0;
	int k, n;
	int x;
	int ans=10000;

	scanf("%d", &n);

	f(i, n){
		scanf("%d", &x);
		a.push_back(x);
	}
		k = 0;
	f(i, n){
		f(j, n - i){
			if (a[j] == 1){
				ans = i;
				k++;
			}
		}
		if (k > 0)break;
		f(j, n - i - 1){
			a[j] = gcd(a[j], a[j + 1]);
		}
	}
	if (ans == 10000){
		printf("-1\n");
	}
	else if (ans == 0){
		printf("%d", n - k);
	}
	else{
		printf("%d\n", ans + n - 1);
	}
	return 0;
}