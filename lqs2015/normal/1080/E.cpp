#include<bits/stdc++.h>
using namespace std;
const long long ph=35119009,mod=8120182601;
long long n,m,num[33],nw,has[255][255][255],ans,nod,hap,pw[255],a[255],b[555],cnt,thre,p[555],mx,id,l[555],r[555];
bool can[255][255][255],f[255],ff[555];
char s[555][555];
void manacher()
{
	mx=id=0;
	for (long long i=2;i<cnt;i++)
    {
        if (i<mx) p[i]=min(mx-i,p[2*id-i]);
        else p[i]=0;
        while(i+p[i]+1<=cnt && i-p[i]-1>=1 && b[i+p[i]+1]==b[i-p[i]-1]) p[i]++;
        if (i+p[i]>mx)
        {
            mx=i+p[i];
            id=i;
        }
    }
}
int main()
{
	srand(time(0));
	thre=(rand()<<10)+rand();
	thre=(thre%mod+mod)%mod;
	scanf("%I64d%I64d",&n,&m);
	for (long long i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	pw[0]=1;
	for (long long i=1;i<=30;i++) pw[i]=pw[i-1]*ph%mod;
	for (long long i=0;i<n;i++)
	{
		for (long long j=0;j<m;j++)
		{
			memset(num,0,sizeof(num));
			nod=hap=0;
			for (long long k=j;k<m;k++)
			{
				num[s[i][k]-'a']++;
				if (num[s[i][k]-'a']&1) nod++;
				else nod--;
				hap=(hap+pw[s[i][k]-'a'])%mod;
				if (nod<2) can[i][j][k]=1;
				else can[i][j][k]=0;
				has[i][j][k]=hap;
			}
		}
	}
	for (long long i=0;i<m;i++)
	{
		for (long long j=i;j<m;j++)
		{
			for (long long k=0;k<n;k++)
			{
				a[k]=has[k][i][j];
				f[k]=can[k][i][j];
			}
			cnt=1;
			b[1]=thre;ff[1]=1;
			for (long long k=0;k<n;k++)
			{
				b[++cnt]=a[k];
				ff[cnt]=f[k];
				b[++cnt]=thre;
				ff[cnt]=1;
			}
			manacher();
			for (long long k=1;k<=cnt;k++)
			{
				if (!ff[k]) l[k]=k;
				else l[k]=l[k-1];
			}
			r[cnt+1]=cnt+1;
			for (long long k=cnt;k>=1;k--) 
			{
				if (!ff[k]) r[k]=k;
				else r[k]=r[k+1];
			}
			for (long long k=2;k<cnt;k++)
			{
				nw=min(p[k],min(k-l[k]-1,r[k]-k-1));
				if (nw<=0) continue;
				ans+=(nw+1)/2;
			}
		}
	}
	printf("%I64d\n",ans);
	return 0;
}