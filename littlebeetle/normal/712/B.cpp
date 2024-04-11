#include<cstdio>
const int N=100002;
char s[N];
int n,i,u,v;
int main(){
	scanf("%s",s+1);
	while(s[n+1])
		n++;
	if(n%2){
		printf("-1");
		return 0;
	}
	for(i=1;i<=n;i++){
		if(s[i]=='U')u++;
		if(s[i]=='D')u--;
		if(s[i]=='R')v++;
		if(s[i]=='L')v--;
	}
	if(u<0)u=-u;
	if(v<0)v=-v;
	printf("%d",u+v>>1);
	//while(1);
}