#include<cstdio>
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
constexpr int N=505;
int tt,n,a[N],b[N],c[N],d[N],m,x[N<<1],y[N<<1],oc[N];
void opt(int u,int v)
{
	F(i,u,(u+v)>>1)swap(a[i],a[u+v-1-i]);
	x[m]=u,y[m]=v;++m;
}
int main()
{
	read(tt);
	while(tt--)
	{
		bool ok;
		read(n);
		F(i,0,n)read(a[i]);
		F(i,0,n)read(b[i]);
		a[n]=b[n]=0;
		F(i,0,n-1)c[i]=min(a[i],a[i+1])<<10|max(a[i],a[i+1]);
		F(i,0,n-1)d[i]=min(b[i],b[i+1])<<10|max(b[i],b[i+1]);
		sort(c,c+(n-1));
		sort(d,d+(n-1));
		ok=a[0]==b[0]&&a[n-1]==b[n-1];
		F(i,0,n-1)ok=ok&&c[i]==d[i];
		if(ok)
		{
			puts("YES");
			m=0;
			F(i,1,n-1)if(a[i]!=b[i])
			{
				int r;
				F(j,i-1,n)if(a[j]==a[i-1])r=j;
				bool done=false;
				F(j,i+1,r)if(a[j]==b[i])
				{
					if(a[j-1]==a[i-1])
					{
						opt(j-1,r+1);
						opt(i-1,r+1);
						done=true;
						break;
					}
					if(a[j+1]==a[i-1])
					{
						opt(i-1,j+2);
						done=true;
						break;
					}
				}
				if(!done)
				{
					++r;
					F(k,0,n+1)oc[k]=-1;
					F(k,i,r)oc[a[k]]=k;
					F(k,r,n)
					{
						if(~oc[a[k]])
						{
							int p=oc[a[k]],q=k;
							opt(p,q+1);
							r=p+q-r;
							opt(i-1,r+2);
							break;
						}
					}
				}
			}
			printf("%d\n",m);
			F(i,0,m)printf("%d %d\n",x[i]+1,y[i]);
		}
		else puts("NO");
	}
	return 0;
}