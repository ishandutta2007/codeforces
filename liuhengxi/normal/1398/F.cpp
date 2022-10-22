#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,s0[N],s1[N],len[N],id[N],f[N];
char s[N];
bool cmp(int u,int v){return len[u]<len[v];}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(n);
	scanf("%s",s);
	F(i,0,n)s0[i+1]=s0[i]+(s[i]=='0');
	F(i,0,n)s1[i+1]=s1[i]+(s[i]=='1');
	for(int i=0,j=0;i<n;++i)
	{
		while(j<n&&(s0[i]==s0[j+1]||s1[i]==s1[j+1]))++j;
		len[i]=j-i;
	}
	F(i,0,n)id[i]=i;
	sort(id,id+n,cmp);
	F(i,0,n+1)f[i]=i;
	for(int x=1,k=0;x<=n;++x)
	{
		int ans=0;
		for(;k<n&&len[id[k]]<x;++k)f[id[k]]=find(id[k]+1);
		for(int i=0;(i=find(i))<n;i+=x)++ans;
		printf("%d ",ans);
	}
	puts("");
	return 0;
}