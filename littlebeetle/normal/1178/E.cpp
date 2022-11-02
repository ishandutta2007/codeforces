#include<cstdio>
const int N=1000002;
char s[N],p[N];
int n,i,j,k;
int main(){
	scanf("%s",s+1);
	for(n=0;s[n+1];n++);
	for(i=2,j=1;i*2<=n;i+=2,j++)
		if(s[i]==s[n-i+1]||s[i]==s[n-i+2])
			p[j]=s[i];
		else
			p[j]=s[i-1];
	for(k=1;k<j;k++)
		printf("%c",p[k]);
	i-=2;
	if(i*2<n)
		printf("%c",s[i+1]);
	for(k=j-1;k;k--)
		printf("%c",p[k]);
	//while(1);
}