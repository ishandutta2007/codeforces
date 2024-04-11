#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair <int, int> pii;

int len[10][10];

int main(){
	int i, j, sum = 0;
	for(i = 1; i <= 3; ++ i){
		scanf("%d%d", &len[i][1], &len[i][2]);
		if(len[i][1] < len[i][2]) swap(len[i][1], len[i][2]);
		sum += len[i][1] * len[i][2];
	}
	int sqr = int(sqrt(double(sum)) + 1e-8);
	if(sqr * sqr != sum){
		printf("-1\n");
		return 0;
	}
	if(len[1][1] == sqr && len[2][1] == sqr && len[3][1] == sqr){
		printf("%d\n", sqr);
		for(i = 1; i <= sqr; ++ i){
			for(j = 1; j <= sqr; ++ j)
				if(i <= len[1][2]) putchar('A');
				else if(i <= len[1][2] + len[2][2]) putchar('B');
				else putchar('C');
			putchar('\n');
		}
		return 0;
	}
	if(len[1][1] == sqr){
		for(i = 1; i <= 2; ++ i){
			for(j = 1; j <= 2; ++ j)
				if(len[2][i] + len[3][j] == sqr){
					if(i ^ j) swap(len[2][1], len[2][2]);
					break;
				}
			if(j != 3) break;
		}
		if(len[2][1] == len[3][1]){
			printf("%d\n", sqr);
			for(i = 1; i <= len[1][2]; ++ i){
				for(j = 1; j <= sqr; ++ j) putchar('A');
				putchar('\n');
			}
			for(; i <= sqr; ++ i){
				for(j = 1; j <= sqr; ++ j)
					putchar('B' + (j <= len[2][2] ? 0 : 1));
				putchar('\n');
			}
			return 0;
		}
		swap(len[2][1], len[2][2]);
		swap(len[3][1], len[3][2]);
		if(len[2][1] == len[3][1]){
			printf("%d\n", sqr);
			for(i = 1; i <= len[1][2]; ++ i){
				for(j = 1; j <= sqr; ++ j) putchar('A');
				putchar('\n');
			}
			for(; i <= sqr; ++ i){
				for(j = 1; j <= sqr; ++ j)
					putchar('B' + (j <= len[2][2] ? 0 : 1));
				putchar('\n');
			}
			return 0;
		}
	}
	if(len[2][1] == sqr){
		for(i = 1; i <= 2; ++ i){
			for(j = 1; j <= 2; ++ j)
				if(len[1][i] + len[3][j] == sqr){
					if(i ^ j) swap(len[1][1], len[1][2]);
					break;
				}
			if(j != 3) break;
		}
		if(len[1][1] == len[3][1]){
			printf("%d\n", sqr);
			for(i = 1; i <= len[2][2]; ++ i){
				for(j = 1; j <= sqr; ++ j) putchar('B');
				putchar('\n');
			}
			for(; i <= sqr; ++ i){
				for(j = 1; j <= sqr; ++ j)
					putchar('A' + (j <= len[1][2] ? 0 : 2));
				putchar('\n');
			}
			return 0;
		}
		swap(len[1][1], len[1][2]);
		swap(len[3][1], len[3][2]);
		if(len[1][1] == len[3][1]){
			printf("%d\n", sqr);
			for(i = 1; i <= len[2][2]; ++ i){
				for(j = 1; j <= sqr; ++ j) putchar('B');
				putchar('\n');
			}
			for(; i <= sqr; ++ i){
				for(j = 1; j <= sqr; ++ j)
					putchar('A' + (j <= len[1][2] ? 0 : 2));
				putchar('\n');
			}
			return 0;
		}
	}
	if(len[3][1] == sqr){
		for(i = 1; i <= 2; ++ i){
			for(j = 1; j <= 2; ++ j)
				if(len[1][i] + len[2][j] == sqr){
					if(i ^ j) swap(len[1][1], len[1][2]);
					break;
				}
			if(j != 3) break;
		}
		if(len[1][1] == len[2][1]){
			printf("%d\n", sqr);
			for(i = 1; i <= len[3][2]; ++ i){
				for(j = 1; j <= sqr; ++ j) putchar('C');
				putchar('\n');
			}
			for(; i <= sqr; ++ i){
				for(j = 1; j <= sqr; ++ j)
					putchar('A' + (j <= len[1][2] ? 0 : 1));
				putchar('\n');
			}
			return 0;
		}
		swap(len[1][1], len[1][2]);
		swap(len[2][1], len[2][2]);
		if(len[1][1] == len[2][1]){
			printf("%d\n", sqr);
			for(i = 1; i <= len[3][2]; ++ i){
				for(j = 1; j <= sqr; ++ j) putchar('C');
				putchar('\n');
			}
			for(; i <= sqr; ++ i){
				for(j = 1; j <= sqr; ++ j)
					putchar('A' + (j <= len[1][2] ? 0 : 1));
				putchar('\n');
			}
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}