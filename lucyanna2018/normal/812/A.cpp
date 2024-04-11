#include<stdio.h>
int a[4][4];
bool chk(){
	for(int i=0; i<4; i++){
		if(a[i][0] && a[(i+3)%4][3])return true;
		if(a[i][1] && a[(i+2)%4][3])return true;
		if(a[i][2] && a[(i+1)%4][3])return true;
		if((a[i][0] || a[i][1] || a[i][2]) && a[i][3])return true;
	}
	return false;
}
int main(){
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			scanf("%d",&a[i][j]);
	puts(chk()?"YES":"NO");
	return 0;
}