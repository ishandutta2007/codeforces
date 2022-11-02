#include<cstdio>
const int N=1000002;
int p1[N],p2[N],n,m,i;
char s1[N],s2[N];
int main(){
	scanf("%s%s",s1+1,s2+1);
	while(s1[n+1])n++;
	for(i=1;i<=n;i++)
		p1[i]=s1[n-i+1]-48;
	while(!p1[n]&&n)n--;
	while(s2[m+1])m++;
	for(i=1;i<=m;i++)
		p2[i]=s2[m-i+1]-48;
	while(!p2[m]&&m)m--;
	if(n!=m){
		if(n>m)
			printf(">");
		else
			printf("<");
		return 0;
	}
	while(n&&p1[n]==p2[n])
		n--;
	if(p1[n]>p2[n])
		printf(">");
	if(p1[n]<p2[n])
		printf("<");
	if(p1[n]==p2[n])
		printf("=");
}