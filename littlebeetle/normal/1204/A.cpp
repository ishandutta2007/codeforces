#include<cstdio>
const int N=10002;
char s[N];
int p[N],n,i;
int main(){
	scanf("%s",s+1);
	if(s[1]==48&&s[2]==0){
		printf("0");
		return 0;
	}
	for(n=0;s[n+1];n++);
	for(i=1;i<=n;i++)
		p[i]=s[n-i+1]-48;
	p[1]--;
	for(i=1;i<n;i++){
		if(p[i]<0)
			p[i]+=2,p[i+1]--;
	}
	if(p[n]==0)
		n--;
	printf("%d",(n+1)/2);
	//while(1);
}