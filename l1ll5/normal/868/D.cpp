#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 205
#define M 50
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int n,m;
int mx=16;
char now_s[N];
int s[N];
char L[N][M],R[N][M];
int topl[N],topr[N];
int bin[N][17];
bool pd[N][17][66666]; 
ll ToT;
int Mn(int a,int b)
{return a<b?a:b;}
int Mx(int a,int b)
{return a>b?a:b;}
void add(int x,int y)
{
	for(int i=1;i<=topl[x];i++)
	now_s[i]=L[x][i];
	for(int i=1;i<=topl[y];i++)
	now_s[topl[x]+i]=L[y][i];
	for(int i=1;i<=Mn(topl[x]+topl[y],mx);i++)
	L[n][++topl[n]]=now_s[i];
		
	int top=0;
	for(int i=topr[y];i;i--)
	now_s[++top]=R[y][i];
	for(int i=topr[x];i;i--)
	now_s[++top]=R[x][i];
	for(int i=1;i<=Mn(topr[x]+topr[y],mx);i++)
	R[n][++topr[n]]=now_s[i];
		
	reverse(R[n]+1,R[n]+topr[n]+1);
		
	for(int i=1;i<=topr[x];i++)
	now_s[i]=R[x][i];
	for(int i=1;i<=topl[y];i++)
	now_s[topr[x]+i]=L[y][i];
}
void pre_cal(int x,int len)
{
	for(int j=1;j<=mx;j++)bin[x][j]=(1<<j);

	for(int j=1;j<=Mn(len,mx);j++)
	{
		int now=0;
		for(int k=1;k<j;k++)
		now<<=1,now+=now_s[k]-'0';
			
		for(int k=j;k<=len;k++)
		{
			now<<=1,now+=now_s[k]-'0';
			now&=(1<<j)-1;
			bin[x][j]-=pd[x][j][now];
			pd[x][j][now]=1;
		}
	}
}
void cal(int x,int y)
{
	int mx_len=topr[x]+topl[y];
	for(int j=1;j<=mx;j++)
	{
		bin[n][j]=1<<j;
		for(int k=0;k<(1<<j);k++)
		{
			ToT++;
			pd[n][j][k]=pd[x][j][k]|pd[y][j][k];
			bin[n][j]-=pd[n][j][k];
		}
		if(j<=mx_len)
		{
			int now=0;
			for(int k=1;k<j;k++)
			now<<=1,now+=now_s[k]-'0';
			for(int k=j;k<=mx_len;k++)
			{
				ToT++;
				now<<=1,now+=now_s[k]-'0';
				now&=(1<<j)-1;
				if(!pd[n][j][now])
				bin[n][j]--;
				pd[n][j][now]=1;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=mx;i++)
	if(!bin[n][i])ans=i;
	printf("%d\n",ans);
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",now_s+1);
		int len=strlen(now_s+1);
		
		for(int j=1;j<=Mn(len,mx);j++)
		L[i][++topl[i]]=now_s[j];
		for(int j=Mx(1,len-mx+1);j<=len;j++)
		R[i][++topr[i]]=now_s[j];
		
		pre_cal(i,len);
	}
	m=read();
	while(m--)
	{
		n++;
		int x=read(),y=read();
		add(x,y),cal(x,y);
	}
}