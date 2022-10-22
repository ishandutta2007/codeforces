#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,INF=0x7fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct trie
{
	static const int N=6e6+5;
	int to[N][2],cnt,num[N],lasta,lastb;
	trie(){cnt=1;}
	void clear()
	{
		cnt=1;to[0][0]=to[0][1]=0;
	}
	void insert(int x,int n)
	{
		int j=0;
		for(int i=29;~i;--i)
		{
			int y=x>>i&1;
			if(!to[j][y])
			{
				to[cnt][0]=to[cnt][1]=0;
				to[j][y]=cnt++;
			}
			j=to[j][y];
		}
		num[j]=n;
	}
	int find(int x)
	{
		int j=0,ans=0;
		for(int i=29;~i;--i)
		{
			int y=x>>i&1;
			if(to[j][y])j=to[j][y];
			else j=to[j][y^1],ans^=1<<i;
		}
		lastb=num[j];
		return lasta=ans;
	}
}trie;
int n,a[N],aa[N],p[N+1],pp[N+1],f[N],cnt,v[N],t[N],l[N],m[N];
long long ans=0;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)p[i]=i;
	p[cnt=n]=n;
	while(cnt>1)
	{
		int ncnt=cnt;
		F(i,0,cnt)f[i]=i,v[i]=INF;
		trie.clear();
		F(i,0,cnt)
		{
			F(j,p[i],p[i+1])
			{
				if(trie.find(a[j])<v[i])
				{
					v[i]=trie.lasta;
					t[i]=trie.lastb;
				}
			}
			F(j,p[i],p[i+1])
			{
				trie.insert(a[j],i);
			}
		}
		trie.clear();
		for(int i=cnt-1;~i;--i)
		{
			F(j,p[i],p[i+1])
			{
				if(trie.find(a[j])<v[i])
				{
					v[i]=trie.lasta;
					t[i]=trie.lastb;
				}
			}
			F(j,p[i],p[i+1])
			{
				trie.insert(a[j],i);
			}
		}
		F(i,0,cnt)
		{
			if(find(i)!=find(t[i]))
			{
				f[find(i)]=find(t[i]);
				ans+=v[i];
				--ncnt;
			}
		}
		F(i,0,cnt)l[i]=0;
		F(i,0,cnt)l[find(i)]+=p[i+1]-p[i];
		F(i,1,cnt)m[i]=m[i-1]+(bool)l[i-1];
		F(i,0,cnt)if(l[i])
			pp[m[i]+1]=pp[m[i]]+l[i];
		F(i,0,ncnt)l[i]=pp[i];
		F(i,0,cnt)
		{
			F(j,p[i],p[i+1])
			{
				aa[l[m[find(i)]]++]=a[j];
			}
		}
		F(i,0,n)a[i]=aa[i];
		F(i,0,ncnt)p[i]=pp[i];
		p[ncnt]=n;
		cnt=ncnt;
	}
	printf("%lld\n",ans);
	return 0;
}