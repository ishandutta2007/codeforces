#include<cstdio>
const int N=55;
int n,p;
int a[N],b[N];
bool flag;
signed main()
{
	int k,i,j;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int check;
	for(k=1;k<=n;k++)
	{
		check=a[k]-b[1]+(a[k]-b[1]>=0?0:p);
		flag=0;
		for(i=1;i<=n-1;i++)
			if(a[(k+i)%n==0?n:(k+i)%n]-b[(i+1)%n==0?n:(i+1)%n]+(a[(k+i)%n==0?n:(k+i)%n]-b[(i+1)%n==0?n:(i+1)%n]>=0?0:p)!=check)
			{
				flag=1;
				break;
			}
		if(!flag)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}