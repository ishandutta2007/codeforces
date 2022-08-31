#include<cstdio>
#include<cstring>
#include<iostream>
#include<bitset>

using namespace std;

const int MaxN=200010;

bitset<7> p[10];

void init()
{
	p[0][0]=p[0][1]=p[0][2]=p[0][4]=p[0][5]=p[0][6]=1;
	p[1][5]=p[1][6]=1;
	p[2][1]=p[2][2]=p[2][3]=p[2][4]=p[2][5]=1;
	p[3][2]=p[3][3]=p[3][4]=p[3][5]=p[3][6]=1;
	p[4][0]=p[4][3]=p[4][5]=p[4][6]=1;
	p[5][0]=p[5][2]=p[5][3]=p[5][4]=p[5][6]=1;
	p[6][0]=p[6][1]=p[6][2]=p[6][3]=p[6][4]=p[6][6]=1;
	p[7][2]=p[7][5]=p[7][6]=1;
	p[8][0]=p[8][1]=p[8][2]=p[8][3]=p[8][4]=p[8][5]=p[8][6]=1;
	p[9][0]=p[9][2]=p[9][3]=p[9][4]=p[9][5]=p[9][6]=1;
}

int n;
char s[MaxN];
int v[MaxN],sum[MaxN];

void work()
{
	scanf("%s",s+1);
	n=strlen(s+1)/2;
	for (int i=1;i<=n*2;++i)
		v[i]=s[i]-'0';
	for (int i=2*n,get=0,most=0;i>n;--i)
	{
		get+=(p[v[i]]&p[v[i-n]]).count();
		for (int k=v[i]+1;k<10;++k)
			if ((p[v[i-n]]&p[k]).count()+most>get)
			{
				for (int j=1;j<i;++j) putchar(v[j]+'0');
				putchar(k+'0');
				get-=(p[v[i-n]]&p[k]).count();
				for (int j=i+1;j<=2*n;++j)
				{
					most-=p[v[j-n]].count();
					for (int x=0;x<10;++x)
						if ((p[v[j-n]]&p[x]).count()+most>get)
						{
							putchar(x+'0');
							get-=(p[v[j-n]]&p[x]).count();
							break;
						}
				}
				return;
			}
		most+=p[v[i-n]].count();
	}
	int get=0;
	for (int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+p[v[i]].count();
		get+=(p[v[i]]&p[v[i+n]]).count();
	}
	for (int i=n;i>=1;--i)
		for (int k=v[i]+1;k<10;++k)
			if (sum[i-1]+p[k].count()+7*(n-i)>get)
			{
				for (int j=1;j<i;++j) putchar(v[j]+'0');
				v[i]=k;
				putchar(k+'0');
				int now=sum[i-1]+p[k].count();
				for (int j=i+1;j<=n;++j)
					for (int x=0;x<10;++x)
						if (now+p[x].count()+7*(n-j)>get)
						{
							v[j]=x;
							putchar(x+'0');
							now+=p[x].count();
							break;
						}
				for (int j=n;j>=1;--j)
					sum[j]=sum[j+1]+p[v[j]].count();
				int have=0;
				for (int j=n+1;j<=2*n;++j)
					for (int x=0;x<10;++x)
						if (have+(p[v[j-n]]&p[x]).count()+sum[j-n+1]>get)
						{
							putchar(x+'0');
							have+=(p[v[j-n]]&p[x]).count();
							break;
						}
				return;
			}
	puts("-1");
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	work();
	return 0;
}