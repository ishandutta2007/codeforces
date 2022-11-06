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
	char c[10];
	int a, b;
	int k, s;
	int n, m;
	int x, y, z;
	int ans = 0;

	a = 0;
	b = 1023;
	scanf("%d", &n);
	f(i, n){
		scanf("%s", c);
		scanf("%d", &x);
		if (c[0] == '&'){
			a = a&x;
			b = b&x;
		}
		else if (c[0] == '|'){
			a = a | x;
			b = b | x;
		}
		else {
			a = a^x;
			b = b^x;
		}
	}
	k = 1;
	x = 0;
	y = 0;
	f(i, 10){
		if (a % 2 == 0){
			if (b % 2 == 0){
				x += k;
				y += k;
			}
		}
		else{
			if (b % 2 == 0)y += k;
			else x += k;
		}
		a = a / 2;
		b = b / 2;
		k = k * 2;
	}
	printf("2\n");
	printf("| %d\n", x);
	printf("^ %d\n", y);

		return 0;
}