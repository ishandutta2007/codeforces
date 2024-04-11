#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=3e7+5,L=17;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int q,to[M][2],ind=N,mn[M];
void insert(int j,int u)
{
	for(int i=L-1;~i;--i)
	{
		int x=u>>i&1;
		if(mn[j]>u)mn[j]=u;
		if(!to[j][x])mn[to[j][x]=++ind]=u;
		j=to[j][x];
	}
	mn[j]=u;
}
int find(int rt,int number,int bit,int mask,int limit)
{
	if(!bit)return number;
	if(!to[rt][0]||mn[to[rt][0]]>limit)return find(to[rt][1],number|bit,bit>>1,mask,limit);
	if(!to[rt][1]||mn[to[rt][1]]>limit)return find(to[rt][0],number    ,bit>>1,mask,limit);
	return find(to[rt][mask&bit?0:1],number|(~mask&bit),bit>>1,mask,limit);
}
int main()
{
	F(i,0,N+1)mn[i]=1<<L;
	read(q);
	while(q--)
	{
		int t;read(t);
		if(t==1)
		{
			int u;read(u);
			for(int i=1;i*i<=u;++i)u%i==0&&(insert(i,u),i*i!=u&&(insert(u/i,u),1));
		}
		else
		{
			int x,k,s;read(x);read(k);read(s);// max x^v  s.t.  k|x, k|v, v<=s-x
			if(x%k||s-x<0){puts("-1");continue;}else s-=x;// s.t.  v<=s, k|v
			if(mn[k]>s)puts("-1");
			else printf("%d\n",find(k,0,1<<(L-1),x,s));
		}
	}
	return 0;
}