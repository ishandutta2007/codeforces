#include<bits/stdc++.h>
#define re register
struct mat
{
	unsigned int x[151][5];
	mat operator *(const mat&A)
	{
		mat c;
		memset(c.x,0,sizeof(c.x));
		for(re int i=1;i<=150;i++)
		{
			for(re int j=1;j<=150;j++)if(x[i][j>>5]&(1u<<(j&31)))
			{
				for(re int k=0;k<5;k++)c.x[i][k]|=A.x[j][k];
			}
		}
		return c;
	}
	void set(re int i,re int j){x[i][j>>5]|=1u<<(j&31);}
	bool che(re int i,re int j){return x[i][j>>5]&(1u<<(j&31));}
}P,P1,B,B1,BK[30];
struct fl{int a,b,d;}ff[210];
inline bool cmp(const fl&A,const fl&B){return A.d<B.d;}
int ans,n;
void clac()
{
	for(re int j=1;j<=n;j++)P.set(j,j);
	BK[0]=P;
	for(re int i=1;i<=29;i++)BK[i]=BK[i-1]*BK[i-1];
	for(re int i=29;i>=0;i--)
	{
		B1=B*BK[i];
		if(!B1.che(1,n))
		{
			ans+=1<<i;
			B=B1;
		}
	}
	ans++;
}
int main()
{
	re int m;
	scanf("%d%d",&n,&m);
	B.set(1,1);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&ff[i].a,&ff[i].b,&ff[i].d);
	}
	std::sort(ff+1,ff+m+1,cmp);
	if(ff[1].d!=0){puts("Impossible");return 0;}
	ff[m+1].d=ff[m].d+2*n;
	for(re int i=1;i<=m;i++)
	{
		P.set(ff[i].a,ff[i].b);
		B1=B;P1=P;
		for(re int j=1;j<=n;j++)P1.set(j,j);
		for(re int j=ff[i+1].d-ff[i].d;j;j>>=1,P1=P1*P1)if(j&1)B1=B1*P1;
		//printf("**%d %d\n",i,B1.che(1,1));
		if(B1.che(1,n))
		{
			clac();
			printf("%d\n",ans+ff[i].d);
			return 0;
		}
		P1=P;
		for(re int j=ff[i+1].d-ff[i].d;j;j>>=1,P1=P1*P1)if(j&1)B=B*P1;
	}
	puts("Impossible");
}