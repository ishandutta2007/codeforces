#include<cstdio>
#include<algorithm>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n,x[N<<1],xv[N],y[N<<1],yv[N],deg[N<<1],vir;
bool ans[N<<1],used[N<<1];
vector<int> to[N<<1];
vector<int>::iterator hd[N<<1];
void dfs(int u)
{
	while(hd[u]!=to[u].end())
	{
		int i=*hd[u];
		++hd[u];
		if(used[i])continue;
		used[i]=true;
		int v=u^x[i]^y[i];
		ans[i]=u==x[i];
		dfs(v);
	}
}
int main()
{
	int last=-1;
	read(n);
	F(i,0,n)read(x[i],y[i]),xv[i]=x[i],yv[i]=y[i];
	sort(xv,xv+n);sort(yv,yv+n);
	F(i,0,n)x[i]=(int)(lower_bound(xv,xv+n,x[i])-xv),y[i]=(int)(lower_bound(yv,yv+n,y[i])-yv)+n;
	F(i,0,n)to[x[i]].push_back(i),to[y[i]].push_back(i),++deg[x[i]],++deg[y[i]];
	vir=n;
	F(i,0,n<<1)if(deg[i]&1)last=~last?(to[x[vir]=last].push_back(vir),to[y[vir]=i].push_back(vir),++vir),-1:i;
	F(i,0,n<<1)hd[i]=to[i].begin();
	F(i,0,n<<1)dfs(i);
	F(i,0,n)putchar(ans[i]?'r':'b');
	puts("");
	return 0;
}