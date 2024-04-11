#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct truck
{
	int v,l,r,tot,id;
	bool operator<(truck b)const{return tot!=b.tot?tot<b.tot:id<b.id;}
}t[N];
int n,f[3*N],last[3*N],pre[N],ans,real[N];
int count(int u){return ~u?count(pre[u])+1:0;}
void print(int u){if(!~u)return;print(pre[u]);printf("%d ",u+1);}
int main()
{
	read(n);
	F(i,0,n)
	{
		int cc,rr;
		read(t[i].v),read(cc),read(t[i].l),read(rr);
		t[i].r=t[i].l+cc;t[i].tot=t[i].r+rr;
		t[i].id=i;
	}
	F(i,0,n)
	{
		const int &now=t[i].tot,&ll=t[i].l,&rr=t[i].r;
		last[0]=now;
		if(last[rr]!=now)last[rr]=now,f[rr]=-INF;
		if(last[ll]==now)if(f[rr]<f[ll]+t[i].v)f[rr]=f[ll]+t[i].v;
		if(last[now]==now)ans=max(ans,f[now]);
	}
	memset(last,0,sizeof last);
	F(i,0,n)
	{
		const int &now=t[i].tot,&ll=t[i].l,&rr=t[i].r;
		last[0]=now;real[0]=-1;
		if(last[rr]!=now)last[rr]=now,f[rr]=-INF;
		if(last[ll]==now)if(f[rr]<f[ll]+t[i].v)f[rr]=f[ll]+t[i].v,pre[i]=real[ll],real[rr]=i;
		if(last[now]==now&&ans==f[now])
		{
			printf("%d\n",count(i));
			print(i);
			puts("");
			return 0;
		}
	}
	puts("0");
	return 0;
}