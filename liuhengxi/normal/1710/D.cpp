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
constexpr int N=2005;
int tt,n,f[N],pos[N],cnt;
char s[N][N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)scanf("%s",s[i]+i);
		F(i,0,n)f[i]=i;
		F(len,1,n+1)
		{
			F(l,0,n-len+1)
			{
				int r=l+len-1;
				if(s[l][r]=='1'&&find(l)!=find(r))
				{
					printf("%d %d\n",l+1,r+1);
					pos[0]=r;pos[1]=l;cnt=2;
					F(i,l+1,find(r))if(find(i)==i)
					{
						printf("%d %d\n",pos[cnt-2]+1,i+1);
						pos[cnt++]=i;
					}
					find(l);
					F(i,l+1,r+1)f[i]=f[l];
				}
			}
		}
	}
	return 0;
}