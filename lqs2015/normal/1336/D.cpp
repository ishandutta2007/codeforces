#include<bits/stdc++.h>
using namespace std;
int a[111],b[111],ans[111],x,y,nx,ny,cnt,fuck[11111],n;
int main()
{
	scanf("%d",&n);
	scanf("%d%d",&x,&y);
	for (int i=n-1;i>=3;i--)
	{
		printf("+ %d\n",i);
		fflush(stdout);
		scanf("%d%d",&nx,&ny); 
		a[++cnt]=nx-x;b[cnt]=ny-y;
		x=nx;y=ny;
	}
	printf("+ %d\n",1);
	fflush(stdout);
	scanf("%d%d",&nx,&ny); 
	a[++cnt]=nx-x;b[cnt]=ny-y;
	x=nx;y=ny;
	printf("+ %d\n",2);
	fflush(stdout);
	scanf("%d%d",&nx,&ny); 
	a[++cnt]=nx-x;b[cnt]=ny-y;
	x=nx;y=ny;
	printf("+ %d\n",1);
	fflush(stdout);
	scanf("%d%d",&nx,&ny); 
	a[++cnt]=nx-x;b[cnt]=ny-y;
	x=nx;y=ny;
	for (int i=0;i<=n;i++)
	{
		fuck[(i+2)*(i+1)*i/6-i*(i-1)*(i-2)/6]=i;
	}
	ans[1]=fuck[a[cnt]+a[cnt-2]];
	ans[3]=b[cnt]-b[cnt-2]-1;
	ans[2]=b[cnt-2]/(ans[3]+1);
	ans[4]=(b[cnt-1]-(ans[1]+1)*(ans[3]+1))/(ans[3]+1)-1;
	for (int i=3;i<=n-2;i++)
	{
		ans[i+2]=(b[cnt-i]-ans[i-1]*ans[i-2]-(ans[i+1]+1)*ans[i-1])/(ans[i+1]+1)-1;
	}
	ans[n]++;
	printf("! ");
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}