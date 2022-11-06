#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(void){
	int a[201];
	int c;
	int b;
	int p;
	int q;
	int r;
	int s;
	int n;
	int m;
	int x, y,z;
	int v;
	scanf("%d %d", &n, &q);
	a[0] = 10000000;
	for (int i = 1; i <= n; i++)a[i] = 0;
	for (int i = n + 1; i < 201; i++)a[i] = 100000000;
	for (int qq = 0; qq < q; qq++){
		c = 0;
		scanf("%d %d %d", &x, &y, &z);
		for (int i = 1; i <= n; i++){
			if (a[i] <= x){
				c++;
			}
		}
		s = 0;
		if (c >= y){
			c = 0;
			for (int i = 1; c<y; i++){
				if (a[i] <= x){
					a[i] = x + z;
					s = s + i;
					c++;
				}
			}
			printf("%d\n", s);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}