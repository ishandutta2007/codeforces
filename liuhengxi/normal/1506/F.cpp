#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,r[N],c[N],id[N],ans,id1[N];
bool cmp(int u,int v){return r[u]<r[v];}
int main()
{
	read(t);
	while(t--)
	{
		ans=0;
		read(n);
		++n;
		F(i,1,n)read(r[i]),id[i]=i;
		r[id[0]=0]=0;
		sort(id,id+n,cmp);
		F(i,0,n)id1[id[i]]=i;
		F(i,0,n)c[i]=r[id[i]];
		F(i,0,n)r[i]=c[i];
		c[0]=0;
		F(i,1,n)read(c[id1[i]]),c[id1[i]]=r[id1[i]]-c[id1[i]],--r[id1[i]];
		F(i,1,n)
		{
			if(c[i]==c[i-1])
			{
				if(!(c[i]&1))ans+=r[i]-r[i-1];
			}
			else
			{
				int tmp=0;
				if(!(c[i]&1))--r[i],--c[i],++tmp;
				if(!(c[i-1]&1))++r[i-1],++c[i-1];
				ans+=(c[i]-c[i-1])/2;
				r[i]+=tmp;c[i]+=tmp;ans+=tmp;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}