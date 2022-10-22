#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4e5+5,LogN=20;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int q,cnt=1,logn=19,fa[N][LogN],p[N][LogN];
long long w[N][LogN],s[N][LogN];
long long max(long long a,long long b){return a>b?a:b;}
int main()
{
	int last=0;
	F(i,0,logn+1)p[0][i]=-1;
	read(q);
	while(q--)
	{
		int op,pp;
		long long qq;
		read(op);read(pp);read(qq);
		if(op==1)
		{
			int r=pp^last,u=cnt++;
			long long ww=qq^last;
			fa[u][0]=--r;
			F(i,0,logn)fa[u][i+1]=fa[fa[u][i]][i];
			w[u][0]=ww;
			F(i,0,logn)w[u][i+1]=max(w[u][i],w[fa[u][i]][i]);
			p[u][0]=fa[u][0];
			for(int i=logn-1;~i;--i)
				if(w[p[u][0]][i]<w[u][0])p[u][0]=fa[p[u][0]][i];
			if(w[p[u][0]][0]<w[u][0])p[u][0]=-1;
			if(~p[u][0])s[u][0]=ww;
			F(i,0,logn)
			{
				if(!~p[u][i])
				{
					F(j,i,logn)p[u][j+1]=-1;
					break;
				}
				s[u][i+1]=s[u][i]+s[p[u][i]][i];
				p[u][i+1]=p[p[u][i]][i];
			}
		}
		else
		{
			int u=pp^last,ans=0;--u;
			long long x=qq^last;
			for(int i=logn-1;~i;--i)
			{
				if(!~p[u][i])continue;
				if(s[u][i]>x)continue;
				x-=s[u][i];u=p[u][i];
				ans+=1<<i;
			}
			if(w[u][0]<=x)++ans;
			printf("%d\n",last=ans);
		}
	}
	return 0;
}