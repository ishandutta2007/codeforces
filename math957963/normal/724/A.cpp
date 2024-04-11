#include<stdio.h>
int main(){
	char a[2][10];
	int b, c;
	int d, e;
	scanf("%s", a[0]);
	scanf("%s", a[1]);
	if (a[0][0] == 'm') b = 1;
	else if (a[0][2] == 'e') b = 2;
	else if (a[0][0] == 'w') b = 3;
	else if (a[0][1] == 'h') b = 4;
	else if (a[0][0] == 'f') b = 5;
	else if (a[0][1] == 'a')b = 6;
	else  b = 0;
	if (a[1][0] == 'm') c = 1;
	else if (a[1][2] == 'e') c = 2;
	else if (a[1][0] == 'w') c = 3;
	else if (a[1][1] == 'h') c = 4;
	else if (a[1][0] == 'f') c = 5;
	else if (a[1][1] == 'a') c = 6;
	else  c = 0;
	d = (b + 2)%7;
	e = (b + 3)%7;
	if (c == b){
		printf("YES\n");
	}
	else if (c == d){
		printf("YES\n");
	}
	else if (c == e){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}