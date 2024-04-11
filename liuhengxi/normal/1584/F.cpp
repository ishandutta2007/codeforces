#include<cstdio>
#include<cstring>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=15,M=110;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int tt,n,f[57][(1<<10)+5],pre[57][(1<<10)+5],pos[N][57][2],q[5700<<10],a[5700<<10],qf,qr,ans,ac,ap;
char s[N][M],anss[M];
int main()
{
	read(tt);
	while(tt--)
	{
		memset(f,0,sizeof f);
		memset(pos,0xff,sizeof pos);
		read(n);
		F(i,0,n)
		{
			scanf("%s",s[i]);
			for(int j=0;s[i][j];++j)
			{
				int *t=pos[i][s[i][j]+(s[i][j]>='a'?-'a'+26:-'A')];
				t[!!~t[0]]=j;
			}
		}
		qf=qr=0;a[qr]=0;q[qr++]=52<<10;
		ans=0;anss[0]=0;ac=52,ap=0;
		for(;qf<qr;++qf)
		{
			int p=q[qf]&1023,c=q[qf]>>10;
			if(f[c][p]>a[qf])continue;
			if(f[c][p]>ans)ans=f[ac=c][ap=p];
			F(d,0,52)
			{
				bool ok=true;int r=0;
				F(k,0,n)
				{
					if(pos[k][d][0]>pos[k][c][p>>k&1]);
					else if(pos[k][d][1]>pos[k][c][p>>k&1])r|=1<<k;
					else ok=false;
				}
				if(ok)
				{
					if(f[c][p]+1>f[d][r])
					{
						a[qr]=f[d][r]=f[c][p]+1;
						q[qr++]=d<<10|r;
						pre[d][r]=c<<10|p;
					}
				}
			}
		}
		printf("%d\n",ans);
		anss[ans]=0;
		for(int cc=ac,pp=ap,lst,tp=ans;f[cc][pp];lst=pre[cc][pp],cc=lst>>10,pp=lst&1023)
			anss[--tp]=(char)(cc+(cc<26?'A':'a'-26));
		puts(anss);
	}
	return 0;
}