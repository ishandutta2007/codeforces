#include<stdio.h>
#include<string.h>
int main(void){
	char a[101];
	int b;
	int c=0;
	int d = 0;
	int e = 0;
	int f = 0;
	int s[50];
	int g[50];
	for (int i = 0; i < 50; i++){
		s[i] = 1000;
		g[i] = 1000;
	}
	scanf("%d", &b);
	scanf("%s", a);
	a[b] = '\0';
	for (int i = 0; i < b+1; i++){
		if (c == 0){
			if (a[i] == 'o'){
				c = 1;
			}
		}
		else if (c == 1){
			if (a[i] == 'g')
			{
				c = 2;
			}
			else{
				if (d == 1){
					g[e] = i - 1;
					e++;
				}
				c = 0;
				d = 0;
				i--;
			}
		}
		else if (c == 2){

			if (a[i] == 'o'){
				if (d == 0){
					s[e] = i - 2;
					d = 1;
				}
				c = 1;
			}
			else{
				if (d == 1){
					g[e] = i - 2;
					e++;
				}
				c = 0;
				d = 0;
				i--;
			}
		}
	}
	d = 0;
	for (int i = 0; i < b; i++){
		if (s[f] == i){
			printf("***");
			i = g[f];
			f++;
		}
		else{
			printf("%c", a[i]);
		}
	}
	printf("\n");
	return 0;
}