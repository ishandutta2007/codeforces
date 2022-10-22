#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=2.5e7+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
namespace trie
{
	int to[N<<4][26],val[N<<4],cnt=1,ind;
	int hash(char *s)
	{
		int j=0;
		for(int i=0;s[i];++i)
		{
			int x=s[i]-'a';
			if(!to[j][x])to[j][x]=cnt++;
			j=to[j][x];
		}
		if(!val[j])val[j]=++ind;
		return val[j]-1;
	}
}
int n,m=1000000000,a[N]/*priority*/,b[N]/*number of assignment*/;
int cnt=1,lc[M],rc[M],val[M],flag;
int update(int p,int l,int r,int x,int v)
{
	int mid=(l+r)>>1,q=cnt++;
	if(r-l==1)
	{
		lc[q]=-1;rc[q]=-1;
		val[q]=flag*val[p]+v;
		return q;
	}
	lc[q]=lc[p];rc[q]=rc[p];
	if(x<mid)lc[q]=update(lc[q],l,mid,x,v);
	else rc[q]=update(rc[q],mid,r,x,v);
	val[q]=val[lc[q]]+val[rc[q]];
	return q;
}
int query(int p,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(!p)return 0;
	if(r-l==1)return x!=l||flag==0?val[p]:0;
	if(x<mid)return query(lc[p],l,mid,x);
	else return flag*val[lc[p]]+query(rc[p],mid,r,x);
}
int main()
{
	read(n);
	F(i,1,n+1)
	{
		char op[7];scanf("%s",op);
		a[i]=a[i-1];b[i]=b[i-1];
		if(op[0]=='s')
		{
			char a1[16];scanf("%s",a1);
			int aa=trie::hash(a1),tmp,x;read(x);
			flag=0;
			tmp=query(a[i],0,n,aa);
			a[i]=update(a[i],0,n,aa,x);
			flag=1;
			if(tmp)b[i]=update(b[i],0,m,--tmp,-1);
			b[i]=update(b[i],0,m,--x,1);
		}
		if(op[0]=='r')
		{
			char a1[16];scanf("%s",a1);
			int aa=trie::hash(a1),tmp;
			flag=0;
			tmp=query(a[i],0,n,aa);
			a[i]=update(a[i],0,n,aa,0);
			flag=1;
			if(tmp)b[i]=update(b[i],0,m,--tmp,-1);
		}
		if(op[0]=='q')
		{
			char a1[16];scanf("%s",a1);
			int aa=trie::hash(a1),tmp;
			flag=0;
			if(tmp=query(a[i],0,n,aa))
			{
				flag=1;
				printf("%d\n",query(b[i],0,m,--tmp));
			}
			else puts("-1");
		}
		if(op[0]=='u')
		{
			int d;read(d);
			a[i]=a[i-1-d];b[i]=b[i-1-d];
		}
		fflush(stdout);
	}
	return 0;
}