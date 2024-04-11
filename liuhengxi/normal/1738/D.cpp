#include<cstdio>
#include<vector>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=1e5+5;
int tt,n,b[N],k,a[N];
bool isl[N];
vector<int> pos[N],st;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)isl[i]=false;
		k=0;
		F(i,0,n)--read(b[i]),k+=b[i]>i;
		F(i,0,n)if(b[i]>=0&&b[i]<n)isl[b[i]]=true,pos[b[i]].emplace_back(i);
		else st.emplace_back(i);
		int m=0;
		auto cmp=[](int u,int v){return isl[u]<isl[v];};
		sort(st.begin(),st.end(),cmp);
		F(i,0,n)sort(pos[i].begin(),pos[i].end(),cmp);
		int nxt=0;
		for(int x:st)
		{
			a[m++]=x;
			if(isl[x])nxt=x;
		}
		while(m<n)
		{
			int u=nxt;
			for(int x:pos[u])
			{
				a[m++]=x;
				if(isl[x])nxt=x;
			}
		}
		st.clear();
		F(i,0,n)pos[i].clear();
		printf("%d\n",k);
		F(i,0,n)printf("%d ",a[i]+1);
		puts("");
	}
	return 0;
}