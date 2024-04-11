#include<cstdio>
const int N=1000002;
int n,i,m;
char s[N];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	scanf("%d%s",&n,s+1);
	m=n/2;
	for(i=1;i<=m;i++)
		if(s[i]=='R'&&s[i+m]=='L')
			printf("%d %d\n",i+m,i);
		else
			printf("%d %d\n",i,i+m);
}