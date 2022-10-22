#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=1020220559,BAS=200569;
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
int pw[N],n,logn,len[N],val[N][21],nex[N][21],fir[N];
char s[N];
int main()
{
	F(i,pw[0]=1,N)pw[i]=(int)(pw[i-1]*(long long)BAS%MOD);
	scanf("%s",s);
	while(s[n])++n;
	s[n]='`';
	while((1<<logn)<n)++logn;
	F(i,0,logn)val[n][i]=nex[n][i]=n;
	fir[n]=n;
	for(int i=n;~--i;)
	{
		bool del;
		if(i+1<n&&s[i]==s[i+1])
		{
			int u=fir[i+2],v;
			if(s[u]!=s[i])del=s[u]<s[i];
			else
			{
				u=nex[u][0],v=fir[i+1];
				for(int j=logn;~--j;)if(val[u][j]==val[v][j])u=nex[u][j],v=nex[v][j];
				if(s[u]==s[v])u=nex[u][0],v=nex[v][0];
				del=s[u]<s[v];
			}
		}
		else del=false;
		if(del)fir[i]=fir[i+2],len[i]=len[fir[i+2]];
		else
		{
			fir[i]=i;
			nex[i][0]=fir[i+1];val[i][0]=s[i];
			len[i]=len[fir[i+1]]+1;
			F(j,0,logn-1)
			{
				nex[i][j+1]=nex[nex[i][j]][j];
				val[i][j+1]=(int)((val[nex[i][j]][j]*(long long)pw[1<<j]+val[i][j])%MOD);
			}
		}
	}
	F(i,0,n)
	{
		printf("%d ",len[i]);
		int j=fir[i];
		if(len[i]<=10)
		{
			while(j<n)putchar(s[j]),j=nex[j][0];
		}
		else
		{
			F(k,0,5)putchar(s[j]),j=nex[j][0];
			for(int k=0,c=len[i]-7;c;c>>=1,++k)if(c&1)j=nex[j][k];
			printf("...");
			F(k,0,2)putchar(s[j]),j=nex[j][0];
		}
		puts("");
	}
	return 0;
}