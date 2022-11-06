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
	char a[100000];
	f(i, 100000)a[i] = 0;
	char b[2];
	char c[2];
	int n, m;
	int x, y;


	scanf("%d %d", &n,&m);
	
	scanf("%s", a);

	f(qq, m){
		scanf("%d %d %s %s", &x, &y, b, c);
		x--;
		for (int i = x; i < y; i++){
			if (a[i] == b[0])a[i] = c[0];
		}
	}

	printf("%s\n", a);

	return 0;
}