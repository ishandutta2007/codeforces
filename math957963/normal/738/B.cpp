#include<stdio.h>
#include<string.h>
int main(void){
	int a[1000][1000];
	int n = 0;
	int m=0;
	int s;
	int g;
	int c = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++){
		s = -1;
		g = -1;
		for (int j = 0; j < m; j++){
			if (a[i][j] == 1){
				if (s < 0){
					s = j;
					g = j;
				}
				else{
					g = j;
				}
			}
		}
		if (s != -1){
			for (int j = 0; j < m; j++){
				if (a[i][j] == 0)
				{
					if (s < j&&j < g)c = c + 2;
					else c++;
				}
			}
		}
	}
	for (int i = 0; i < m; i++){
		s = -1;
		g = -1;
		for (int j = 0; j < n; j++){
			if (a[j][i] == 1){
				if (s < 0){
					s = j;
					g = j;
				}
				else{
					g = j;
				}
			}
		}
		if (s != -1){
			for (int j = 0; j < n; j++){
				if (a[j][i] == 0)
				{
					if (s < j&&j < g)c = c + 2;
					else c++;
				}
			}
		}
	}
	printf("%d\n", c);
	return 0;
}