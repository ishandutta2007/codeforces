#include<cstdio>
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
constexpr int N=2e5+5;
int tt,n,sta[N],top,mat[N],f[N];
char s[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(tt);
	while(tt--)
	{
		int ans=0;
		read(n);
		scanf("%s",s);
		F(i,0,2*n)mat[i]=-1,f[i]=i;
		top=0;
		F(i,0,2*n)
		{
			if(s[i]=='(')sta[top++]=i;
			else
			{
				mat[mat[i]=sta[--top]];
				f[find(mat[i])]=find(i);
			}
		}
		F(i,0,2*n-1)if(s[i]==')'&&s[i+1]=='(')f[find(i)]=find(i+1);
		F(i,0,2*n)if(find(i)==i)++ans;
		printf("%d\n",ans);
	}
	return 0;
}