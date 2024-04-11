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
	int a[100];
	f(i, 100)a[i] = 0;
	int k, n;
	int w, x, y;
	bool z = true;


	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
	}
	w = 3;
	x = 1;
	y = 2;
	f(i, n){
		if (a[i] == w){
			z = false;
			break;
		}
		else if (a[i] == x){
			k = y;
			y = w;
			w = k;
		}
		else if (a[i] == y){
			k = x;
			x = w;
			w = k;
		}
	}
	if (z)printf("YES\n");
	else printf("NO\n");

	return 0;
}