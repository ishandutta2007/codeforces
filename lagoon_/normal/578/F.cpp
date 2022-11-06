#include<bits/stdc++.h>
#define re register
int x[100010],y[100010],ff[100100],xx[450][450],fa[1000100],mod;
char ss[100100];
void add(re int&a){a=(a+1)%mod;}
void sub(re int&a){a=(a+mod-1)%mod;}
int find(re int a){return a==fa[a]?a:fa[a]=find(fa[a]);}
void meg(re int a,re int b)
{
	a=find(a);b=find(b);
	fa[a]=b;
}
int ex(re int a,re int b)
{
	re int ans=1;
	for(;b;b>>=1,a=(long long)a*a%mod)if(b&1)ans=(long long)ans*a%mod;
	return ans;
}
int main()
{
	re int n,m,m1=0,tn=0,ans=0,t1=0,t2=0;
	scanf("%d%d%d",&n,&m,&mod);
	//if(n==100&&m==100)return 0;
	for(re int i=1;i<=(n+1)*(m+1);i++)fa[i]=i;
	for(re int i=0;i<n;i++)
	{
		scanf("%s",ss+1);
		for(re int j=1;j<=m;j++)
		{
			if(ss[j]=='\\')meg(i*(m+1)+j,(i+1)*(m+1)+j+1),(((i+j)&1)?t1++:t2++);
			else if(ss[j]=='/')meg((i+1)*(m+1)+j,i*(m+1)+j+1),(((i+j+1)&1)?t1++:t2++);
			else x[++m1]=i,y[m1]=j;
		}
	}
	//if(n==100&&m==100)return 0;
	for(re int i=0;i<=n;i++)
	{
		for(re int j=1+(i&1);j<=m+1;j+=2)
		{
			if(!ff[find(i*(m+1)+j)])
			ff[find(i*(m+1)+j)]=++tn;
			t1--;
		}
		//printf("**%d %d %d\n",i,j,ff[find((i*(m+1)+j))]);
	}//printf("**%d\n",tn);
	if(tn<410&&t1==-tn)
	{
		for(re int i=1;i<=m1;i++)
		{
			re int x1,x2;
			if((x[i]+y[i])&1)x1=ff[find(x[i]*(m+1)+y[i])],x2=ff[find((x[i]+1)*(m+1)+y[i]+1)];
			else x1=ff[find(x[i]*(m+1)+y[i]+1)],x2=ff[find((x[i]+1)*(m+1)+y[i])];
			sub(xx[x1][x2]);sub(xx[x2][x1]);add(xx[x1][x1]);add(xx[x2][x2]);
		}
		re int num=1;tn--;
		for(re int i=1;i<=tn;i++)
		{
			re int j=i;
			for(;j<=tn&&!xx[j][i];j++);
			if(j>tn)continue;
			if(j!=i)num=-num;
			std::swap(xx[j],xx[i]);
			for(j++;j<=tn;j++)if(xx[j][i])
			{
				re int inv=(long long)xx[j][i]*ex(xx[i][i],mod-2)%mod;
				//assert((long long)inv*xx[i][i]%mod==xx[j][i]);
				for(re int k=i;k<=tn;k++)xx[j][k]=(xx[j][k]+(long long)(mod-xx[i][k])*inv)%mod;
				//assert(!xx[j][i]);
			}
		}
		num=(num+mod)%mod;
		for(re int i=1;i<=tn;i++)num=(long long)num*xx[i][i]%mod;
		ans=num;
	}
	tn=0;
	memset(xx,0,sizeof(xx));
	for(re int i=0;i<=n;i++)
	{
		for(re int j=2-(i&1);j<=m+1;j+=2)
		{
			if(!ff[find(i*(m+1)+j)])ff[find(i*(m+1)+j)]=++tn;
			t2--;
		}
	}//printf("**%d %d\n",ans,tn);
	if(tn<410&&t2==-tn)
	{
		for(re int i=1;i<=m1;i++)
		{
			re int x1,x2;
			if(!((x[i]+y[i])&1))x1=ff[find(x[i]*(m+1)+y[i])],x2=ff[find((x[i]+1)*(m+1)+y[i]+1)];
			else x1=ff[find(x[i]*(m+1)+y[i]+1)],x2=ff[find((x[i]+1)*(m+1)+y[i])];
			sub(xx[x1][x2]);sub(xx[x2][x1]);add(xx[x1][x1]);add(xx[x2][x2]);
			//printf("**%d %d %d %d\n",x1,x2,x[i],y[i]);
		}
		re int num=1;tn--;
		for(re int i=1;i<=tn;i++)
		{
			re int j=i;
			for(;j<=tn&&!xx[j][i];j++);
			if(j>tn)continue;
			if(j!=i)num=-num;
			std::swap(xx[j],xx[i]);
			for(j++;j<=tn;j++)if(xx[j][i])
			{
				re int inv=(long long)xx[j][i]*ex(xx[i][i],mod-2)%mod;
				//assert((long long)inv*xx[i][i]%mod==xx[j][i]);
				for(re int k=i;k<=tn;k++)xx[j][k]=(xx[j][k]+(long long)(mod-xx[i][k])*inv)%mod;
			}
		}
		num=(num+mod)%mod;
		//printf("**%d\n",num);
		//for(re int i=1;i<=tn;i++)for(re int j=1;j<=tn;j++)printf("%d%c",xx[i][j],(j==tn)?'\n':' ');
		for(re int i=1;i<=tn;i++)num=(long long)num*xx[i][i]%mod;
		ans=(ans+num)%mod;
	}
	printf("%d\n",ans);
}