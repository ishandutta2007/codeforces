#include<bits/stdc++.h>
#define re register
bool in[15010],vis[15010];
int main()
{
	re int n,k,B;
	re char c;
	scanf("%d%d",&n,&k);
	if(k==1)B=1;
	else B=k/2;
	for(re int i=1;i<n/B;i++)
	{
		for(re int j=0;j<n/B;j++)vis[j]=0;
		for(re int j=0;j<n/B-i;j++)if(!vis[j])
		{
			printf("R\n");
			for(re int i1=j;i1<n/B;i1+=i)
			{
				vis[i1]=1;
				for(re int i2=i1*B+1;i2<=i1*B+B;i2++)
				if(!in[i2]){
					printf("? %d\n",i2);
					fflush(stdout);
					for(c=getchar();c!='Y'&&c!='N';c=getchar());
					in[i2]=(c=='Y');
				}
			}
		}
	}
	re int ans=0;
	for(re int i=1;i<=n;i++)ans+=(!in[i]);
	printf("! %d\n",ans);
}