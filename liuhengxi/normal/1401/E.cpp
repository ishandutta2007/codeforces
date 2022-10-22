#include<cstdio>//
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,S=1000000;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int x,y,t;
}l[2*N];
bool cmp1(line a,line b){return a.x!=b.x?a.x<b.x:a.t<b.t;}
bool cmp2(line a,line b){return a.x!=b.x?a.x>b.x:a.t<b.t;}
int n,m,cnt,c[S+1];
long long ans=1;
inline int lowbit(int x){return x&-x;}
void add(int x){for(++x;x<=S;x+=lowbit(x))++c[x];}
int sum(int x)
{
	int res=0;
	for(;x;x-=lowbit(x))res+=c[x];
	return res;
}
int main()
{
	read(n);read(m);
	F(i,0,n)
	{
		int y,lx,rx;
		read(y);read(lx);read(rx);
		if(lx==0)l[cnt].t=0,l[cnt].x=rx,l[cnt++].y=y;
		else l[cnt].t=1,l[cnt].x=lx,l[cnt++].y=y;
		if(lx==0&&rx==S)++ans;
	}
	F(i,0,m)
	{
		int x,ly,ry;
		read(x);read(ly);read(ry);
		if(ly==0)l[cnt].t=2,l[cnt].y=ry,l[cnt++].x=x;
		else l[cnt].t=3,l[cnt].y=ly,l[cnt++].x=x;
		if(ly==0&&ry==S)++ans;
	}
	sort(l,l+cnt,cmp1);
	F(i,0,cnt)
	{
		if(l[i].t==1)
		{
			add(l[i].y!=S?l[i].y:S-1);
		}
		if(l[i].t==2)
		{
			ans+=sum(l[i].y!=S?l[i].y+1:S);
		}
		if(l[i].t==3)
		{
			ans+=sum(S)-sum(l[i].y);
		}
	}
	sort(l,l+cnt,cmp2);
	F(i,0,S)c[i+1]=0;
	F(i,0,cnt)
	{
		if(l[i].t==0)
		{
			add(l[i].y!=S?l[i].y:S-1);
		}
		if(l[i].t==2)
		{
			ans+=sum(l[i].y!=S?l[i].y+1:S);
		}
		if(l[i].t==3)
		{
			ans+=sum(S)-sum(l[i].y);
		}
	}
	printf("%lld\n",ans);
	return 0;
}