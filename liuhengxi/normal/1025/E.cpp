#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=55,K=10800;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,x[N],y[N],ansx[2][2][K],ansy[2][2][K],k[2],st,id[N],tx[N],p,d[N];
bool done[N];
bool cmp(int a,int b){return x[a]<x[b];}
void move(int x1,int y1,int x2,int y2)
{
	if(x1==x2)
	{
		if(y1<y2)
		{
for(int i=y1;i!=y2;++i){ansx[st][st^0][k[st]]=x1;ansy[st][st^0][k[st]]=i;
ansx[st][st^1][k[st]]=x1;ansy[st][st^1][k[st]]=i+1;++k[st];}
		}
		if(y1>y2)
		{
for(int i=y1;i!=y2;--i){ansx[st][st^0][k[st]]=x1;ansy[st][st^0][k[st]]=i;
ansx[st][st^1][k[st]]=x1;ansy[st][st^1][k[st]]=i-1;++k[st];}
		}
	}
	else
	{
		if(x1<x2)
		{
for(int i=x1;i!=x2;++i){ansy[st][st^0][k[st]]=y1;ansx[st][st^0][k[st]]=i;
ansy[st][st^1][k[st]]=y1;ansx[st][st^1][k[st]]=i+1;++k[st];}
		}
		if(x1>x2)
		{
for(int i=x1;i!=x2;--i){ansy[st][st^0][k[st]]=y1;ansx[st][st^0][k[st]]=i;
ansy[st][st^1][k[st]]=y1;ansx[st][st^1][k[st]]=i-1;++k[st];}
		}
	}
}
void solve()
{
	F(i,0,m)read(x[i]),read(y[i]),--x[i],--y[i],id[i]=i;
	sort(id,id+m,cmp);
	F(i,0,m)tx[id[i]]=i;
	F(i,0,n)
	{
		int donecnt=0;
		p=0;
		F(j,0,m)if(y[id[j]]==i)d[p++]=id[j];
		F(j,0,p)done[j]=false;
		while(donecnt<p)F(j,0,p)if(!done[j])
		{
			if((j==0||x[d[j-1]]<tx[d[j]])&&(j==p-1||x[d[j+1]]>tx[d[j]]))
			{
				move(x[d[j]],y[d[j]],tx[d[j]],y[d[j]]);
				done[j]=true,donecnt++;
				x[d[j]]=tx[d[j]];
			}
		}
	}
	F(i,0,m)move(tx[i],y[i],tx[i],i);
	F(i,0,m)move(tx[i],i,i,i);
}
int main()
{
	read(n);read(m);
	solve();
	st=1;
	solve();
	printf("%d\n",k[0]+k[1]);
	F(i,0,k[0])printf("%d %d %d %d\n",ansx[0][0][i]+1,ansy[0][0][i]+1,
	ansx[0][1][i]+1,ansy[0][1][i]+1);
	for(int i=k[1]-1;~i;--i)printf("%d %d %d %d\n",ansx[1][0][i]+1,ansy[1][0][i]+1,
	ansx[1][1][i]+1,ansy[1][1][i]+1);
	return 0;
}