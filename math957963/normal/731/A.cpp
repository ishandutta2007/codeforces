#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n = 0;;
	char a[10001];
	int s = 0;
	int x = 0;
	for (int i = 0; i < 10001; i++){
		a[i] = NULL;
	}
		scanf("%s", a);
	n = strlen(a);
	x = 97;
	for (int i = 0; i < n; i++){
		if (x < a[i]){
			if ((a[i] - x) < (26 + x - a[i]))
			{
				s = s + a[i] - x;
				x = a[i];
			}
			else {
				s = s + 26 + x - a[i];
				x = a[i];
			}
		}
			else if (x > a[i]){
				if (( x - a[i]) < (26 +a[i] - x))
				{
					s = s + x - a[i] ;
					x =a[i] ;
				}
				else {
					s = s + 26 +a[i] - x;
					x = a[i];
				}
		}
	}
	printf("%d", s);
	return 0;
}