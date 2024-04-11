#include<cstdio>
const int N=100002;
char s[N],t[N];
int n,a,b;
int main(){
	scanf("%s%s",s+1,t+1);
	for(n=1;s[n];n++){
		if(s[n]=='4'&&t[n]=='7')
			a++;
		if(s[n]=='7'&&t[n]=='4')
			b++;
	}
	printf("%d",a>b?a:b);
	//while(1);
}