#include<cstdio>
const int N=100002;
char s[N];
int x,y,i;
int main(){
	scanf("%s",s+1);
	for(i=1;s[i];i++)
		if(s[i]=='0')
			printf("1 %d\n",x+1),x=(x+1)%4;
		else
			printf("3 %d\n",y+1),y=(y+2)%4;
	//while(1);
}