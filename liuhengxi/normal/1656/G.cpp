#include<cstdio>
#include<vector>
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
int tt,n,a[N],b[N],c[N],f[N],node[N],m;
vector<int> pos[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(tt);
	while(tt--)
	{
		bool odd=false,no=false;
		F(i,0,read(n))--read(a[i]);
		F(i,0,n)c[i]=0;
		F(i,0,n)++c[a[i]];
		F(i,0,n)if(c[i]&1)
		{
			if(odd)no=true;
			else odd=true;
		}
		if((n&1)&&c[a[n>>1]]==1)no=true;
		if(no){puts("NO");continue;}
		puts("YES");
		F(i,0,n)pos[a[i]].emplace_back(i);
		for(int i=0,j=0;i<n;++i)while(c[i])if(c[i]>1)
		{
			b[j]=pos[i][--c[i]];
			b[n-1-j]=pos[i][--c[i]];
			++j;
		}
		else b[n>>1]=pos[i][--c[i]];
		F(i,0,n)f[i]=i;
		F(i,0,n)f[find(i)]=find(b[i]);
		F(i,0,n>>1)if(find(i)!=find(n-1-i))
		{
			f[f[i]]=f[n-1-i];
			swap(b[i],b[n-1-i]);
		}
		int mid=n&1?n>>1:-1;
		m=0;
		F(i,0,n)if(i!=mid&&find(i)==i)node[m++]=i;
		int t1=b[node[0]],t2=b[n-1-node[0]];
		F(i,0,m-1)b[node[i]]=b[n-1-node[i+1]],b[n-1-node[i]]=b[node[i+1]];
		b[node[m-1]]=t1;
		b[n-1-node[m-1]]=t2;
		if((n&1)&&b[mid]==mid)
		{
			F(i,0,n)if(i!=mid&&a[b[i]]==a[mid])
			{
				swap(b[i],b[mid]);
				break;
			}
		}
		F(i,0,n)printf("%d ",b[i]+1);
		puts("");
		F(i,0,n)pos[i].clear(),pos[i].shrink_to_fit();
	}
	return 0;
}