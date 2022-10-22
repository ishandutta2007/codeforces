#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],id[N],c/*c_i: the number of i-len intervals*/[N],t,f[N],s[N],maxpos,mink;
bool con/*consecutive*/[N];
bool cmp(int u,int v){return a[u]<a[v];}
void add(int x){if(!c[x])++t;++c[x];}void del(int x){--c[x];if(!c[x])--t;}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y)
{
	if((x=find(x))==(y=find(y)))return;
	del(s[x]);del(s[y]);
	if(s[x]<s[y])x^=y^=x^=y;
	s[x]+=s[y];f[y]=x;
	add(s[x]);
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),id[i]=i;
	sort(id,id+n,cmp);
	F(i,0,n)f[i]=i;
	for(int l=0,r=0;l<n;l=r)
	{
		int pos,len,k=a[id[l]]+1;
		while(r<n&&a[id[l]]==a[id[r]])++r;
		F(i,l,r)
		{
			con[id[i]]=true;
			add(s[id[i]]=1);
			if(id[i]&&con[id[i]-1])merge(id[i],id[i]-1);
			if(con[id[i]+1])merge(id[i],id[i]+1);
			len=s[find(id[i])];
		}
		if(t>1)continue;
		pos=c[len];
		if(pos>maxpos)maxpos=pos,mink=k;
	}
	printf("%d\n",mink);
	return 0;
}