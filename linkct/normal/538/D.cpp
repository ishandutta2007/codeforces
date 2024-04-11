#include <cstdio>
#define avail(i, j) (Avail[i + 51][j + 51])
const int MAXN = 55;

char cb[MAXN][MAXN];
bool Avail[MAXN << 1][MAXN << 1];
int n, attack[MAXN][MAXN];

inline bool inmap(int a, int b){return a >= 1 && b >= 1 && a <= n && b <= n;}
int main(){
	int i, j, _i, _j;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%s", cb[i] + 1);
	for(i = 1 - n; i <= n - 1; ++ i)
		for(j = 1 - n; j <= n - 1; ++ j)
			avail(i, j) = true;
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j){
			if(cb[i][j] != 'o') continue;
			for(_i = 1; _i <= n; _i ++)
				for(_j = 1; _j <= n; _j ++)
					if(cb[_i][_j] == '.')
						avail(_i - i, _j - j) = false;
		}
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j){
			if(cb[i][j] != 'o') continue;
			for(_i = 1 - n; _i <= n - 1; ++ _i)
				for(_j = 1 - n; _j <= n - 1; ++ _j)
					if(avail(_i, _j) && inmap(i + _i, j + _j))
						attack[i + _i][j + _j] ++;
		}
	for(i = 1; i <= n; ++ i)
		for(j = 1; j <= n; ++ j)
			if(cb[i][j] == 'x' && !attack[i][j]){
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
	for(i = 1 - n; i <= n - 1; ++ i){
		for(j = 1 - n; j <= n - 1; ++ j){
			if(i == 0 && j == 0){
				putchar('o');
				continue;
			}
			if(avail(i, j)) putchar('x');
			else putchar('.');
		}
		putchar('\n');
	}
	return 0;
}