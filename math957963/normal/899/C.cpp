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
	int n;
	int x, y, z;
	int ans = 0;

	scanf("%d", &n);

	if (n % 2 == 0){
		if (n % 4 == 0)printf("0\n");
		else printf("1\n");
		printf("%d ", (n / 2) );
		x = 0;
		f(i, n){
			if ((i % 4 == 0) || (i % 4 == 3)){
				printf("%d", i + 1);
				x++;
				if (x < (n/2))printf(" ");
			}
		}
		printf("\n");
	}
	else{
		if (n % 4 == 3){
			printf("0\n");
			y = (n - 3) / 2;
			printf("%d ", y + 2);
			x = 0;
			f(i, y){
				if ((i % 4 == 0) || (i % 4 == 3)){
					printf("%d ", i + 1);
					x++;
				}
			}
			printf("%d %d", y + 1, y + 2);
			x += 2;
			if (x < (y + 2))printf(" ");
			for (int i = y + 2; i < n - 1; i++){
				if ((i % 4 == 1) || (i % 4 == 2)){
					printf("%d", i + 1);
					x++;
					if (x < (y + 2))printf(" ");
				}
			}
			printf("\n");
		}
		else{
			printf("1\n");
			if (n % 8 == 1){
				printf("%d ", (n / 2));
				f(i, n-1){
					if ((i % 4 == 0) || (i % 4 == 3)){
						if ((2*i)+1 != n){
							printf("%d ", i + 1);
						}
					}
				}
				printf("%d\n",n);
			}
			else{
				printf("%d ", (n / 2) + 1);
				x = 0;
				f(i, n-1){
					if ((i % 4 == 0) || (i % 4 == 3)){
							printf("%d", i + 1);
							x++;
							if (x < (n / 2)+1)printf(" ");
					}
					else if (2 * i + 3 == n){
						printf("%d", i + 1);
						x++;
						if (x < (n / 2)+1)printf(" ");
					}
				}
			}
		}
	}
	return 0;
}