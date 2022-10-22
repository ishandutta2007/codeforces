#include <bits/stdc++.h>
using namespace std;
#define N 1005
int T,n,m,t1,t2,t3;char a[N][N]; 
void slv()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",a[i]+1);
	for(int i=1;i<=n;++i) for(int j=1;j<i;++j)
		if(a[i][j]==a[j][i])
		{
			puts("YES");
			for(int k=1;k<=m+1;++k)
				printf("%d ",k&1?i:j);puts("");return;
		} 
	if(m&1)
	{
		puts("YES");
		for(int i=1;i<=m+1;++i)
			printf("%d ",i&1?1:2);puts("");return;
	}if(n<3) {puts("NO");return;}
	if(a[1][2]==a[2][3] && a[1][2]==a[3][1])
	{
		puts("YES");
		for(int i=1;i<=m+1;++i)
			printf("%d ",i%3+1);puts("");return;
	}puts("YES");
	if(a[1][2]==a[2][3]) t1=1,t2=2,t3=3;	
	else if(a[1][3]==a[3][2]) t1=1,t2=3,t3=2;
	else t1=2,t2=1,t3=3;
	if(m%4==2)
	{
		for(int i=1;i<=m/4;++i) printf("%d %d ",t1,t2);
		printf("%d %d %d ",t1,t2,t3);
		for(int i=1;i<=m/4;++i) printf("%d %d ",t2,t3);
		puts("");return;
	}printf("%d ",t2);
	for(int i=1;i<=m/4;++i) printf("%d %d ",t3,t2);
	for(int i=1;i<=m/4;++i) printf("%d %d ",t1,t2);puts(""); 
}
int main() {scanf("%d",&T);while(T--) slv();return 0;}