#include<cstdio>
#include<vector>
#include<bitset>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505,M=6e5+5;
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
struct query{int id,x1,y1,x2,y2;};
int n,m,q,ans[M];
char s[N][N];
bitset<N> f[N][N];
void solve(int l,int r,vector<query> qy)
{
	int mid=(l+r)>>1;
	vector<query> left,right;
	F(i,l,r)F(j,0,n)f[i][j].reset();
	if(r-l==1)
	{
		for(int i=m;~--i;)if(s[l][i]=='.')f[l][i]=f[l][i+1],f[l][i][i]=1;
		for(query p:qy)ans[p.id]=f[l][p.y1][p.y2];
		return;
	}
	for(int i=m;~--i;)if(s[mid-1][i]=='.')f[mid-1][i]=f[mid-1][i+1],f[mid-1][i][i]=1;
	for(int i=mid-1;--i>=l;)for(int j=m;~--j;)if(s[i][j]=='.')f[i][j]=f[i][j+1]|f[i+1][j];
	F(i,0,m)if(s[mid][i]=='.')(i&&(f[mid][i]=f[mid][i-1],1)),f[mid][i][i]=1;
	F(i,mid+1,r)F(j,0,m)if(s[i][j]=='.')(j&&(f[i][j]=f[i][j-1],1)),f[i][j]|=f[i-1][j];
	for(query p:qy)
	{
		if(p.x2<mid)left.push_back(p);
		else if(p.x1>=mid)right.push_back(p);
		else ans[p.id]=(f[p.x1][p.y1]&f[p.x2][p.y2]).any();
	}
	solve(l,mid,left);
	solve(mid,r,right);
}
int main()
{
	vector<query> all;
	read(n,m);
	F(i,0,n)scanf("%s",s[i]);
	read(q);
	F(i,0,q)
	{
		int x1,y1,x2,y2;
		read(x1,y1,x2,y2),--x1,--y1,--x2,--y2;
		all.push_back(query({i,x1,y1,x2,y2}));
	}
	solve(0,n,all);
	F(i,0,q)puts(ans[i]?"Yes":"No");
	return 0;
}