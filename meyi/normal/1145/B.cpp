#include<cstdio>
bool a[10];
int n;
main(){
	scanf("%d",&n);
	a[1]=a[7]=a[9]=true;
	puts(n!=12&&(a[n%10]||a[n/10]||n>9&&n<30)?"No":"Yes");
}