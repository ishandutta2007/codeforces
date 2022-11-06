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
	char a[9][3][4];
	f(i, 9){
		f(j, 3){
			f(k, 4)a[i][j][k] = 0;
		}
	}
	int s;
	int n;
	bool v=true;
	int x, y;

	f(i, 9){
		f(j, 3)scanf("%s", a[i][j]);
	}
	scanf("%d %d", &x, &y);
	x = (x + 2) % 3;
	y = (y + 2) % 3;
	f(i, 3){
		f(j, 3){
			if (a[3 * x + i][y][j] == '.'){
				v = false;
				a[3 * x + i][y][j] = '!';
			}
		}
	}
	if (v){
		f(i, 9){
			f(j, 3){
				f(k, 3){
					if (a[i][j][k] == '.')a[i][j][k] = '!';
				}
			}
		}
	}
	f(i, 9){
		f(j, 3){
			f(k, 3){
				printf("%c", a[i][j][k]);
			}
			if (j < 2)printf(" ");
			else printf("\n");
		}
		if (i % 3 == 2&&i<8)printf("\n");
	}
	return 0;
}