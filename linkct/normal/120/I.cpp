#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

#define ll long long
#define inf 1e9
#define eps 1e-10
#define md
#define N 200010
using namespace std;

bool chr[10][7]={
	{1,0,1,1,1,1,1},
	{0,0,0,0,0,1,1},
	{1,1,1,0,1,1,0},
	{1,1,1,0,0,1,1},
	{0,1,0,1,0,1,1},
	{1,1,1,1,0,0,1},
	{1,1,1,1,1,0,1},
	{1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
int lucky[10][10],sm[10];
char st[N];
int a[N],pr[N];
bool fr[N];

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); 
	for (int i=0;i<10;i++)
	{
	  for (int j=0;j<10;j++)
	    for (int k=0;k<7;k++)
	      lucky[i][j]+=(chr[i][k]&chr[j][k]);
	  for (int k=0;k<7;k++) sm[i]+=chr[i][k];
	}
	scanf("%s",st+1);
	int n=strlen(st+1);
	for (int i=1;i<=n;i++) a[i]=st[i]-'0';
	for (int i=1;i<=(n/2);i++)
	{
		fr[i]=1; pr[i]=i+n/2; pr[i+n/2]=i;
	}
	int ok=0;
	int der=0,nd=0;
	for (int i=n;i&&(!ok);i--)
	{
		if (!fr[i])
		{
			int xx=a[pr[i]],nn=a[i];
			for (int j=nn+1;j<10;j++)
			{
				if (der+lucky[xx][j]-lucky[nn][xx]>0)
				{
					a[i]=j; ok=i;
					nd=lucky[xx][j]-lucky[nn][xx];
					break;
				}
			}
			if (!ok) der+=sm[xx]-lucky[nn][xx];
			//printf("der %d nn %d xx %d lucky %d\n",der,nn,xx,lucky[nn][xx]);
		}
		else
		{
			int xx=a[pr[i]],nn=a[i];
			der-=sm[nn]-lucky[nn][xx];
			//printf("der %d\n",der);
			for (int j=nn+1;j<10;j++)
			{
				if (der+sm[j]-lucky[nn][xx]>0)
				{
					a[i]=j; ok=i;
					nd=sm[j]-lucky[nn][xx];
					break;
				}
			}
			if (!ok) der+=7-lucky[nn][xx];
		}
	}
	//printf("nd %d\n",nd);
	if (!ok) {printf("-1\n"); return 0;}
	else
	{
		if (!fr[ok])
		{
			for (int i=ok+1;i<=n;i++)
			{
				int xx=a[pr[i]],nn=a[i];
				der-=sm[xx]; der+=lucky[nn][xx];
				for (int j=0;j<=9;j++)
				{
					if (der+nd+lucky[j][xx]-lucky[nn][xx]>0)
					{
						a[i]=j; nd+=lucky[j][xx]-lucky[nn][xx];
						break;
					}
				}
			}
		}
		else
		{
			for (int i=ok+1;i<=n;i++)
			{
				int xx=a[pr[i]],nn=a[i];
				if (fr[i])
				{
					der-=7-lucky[xx][nn];
					for (int j=0;j<=9;j++)
					{
						if (der+nd+sm[j]-lucky[nn][xx]>0)
						{
							a[i]=j; nd+=sm[j]-lucky[nn][xx];
							break;
						}
					}
				}	
				else if (pr[i]<ok)
				{
					der-=sm[xx]-lucky[xx][nn];
					//printf("_der %d\n",der);
					for (int j=0;j<=9;j++)
					{
						if (der+nd+lucky[xx][j]-lucky[xx][nn]>0)
						{
							a[i]=j; nd+=lucky[xx][j]-lucky[xx][nn];
							break;
						}
					}
				}
				else
				{
					nd-=sm[xx];
					//printf("nd der %d %d\n",nd,der);
					for (int j=0;j<=9;j++)
					{
						if (der+nd+lucky[xx][j]>0)
						{
							a[i]=j; nd+=lucky[xx][j];
							break;
						}
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d",a[i]); printf("\n");
	return 0;
}