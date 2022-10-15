//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 200005
#define int long long

using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int dep[N],fa[N],gfa[N][21],gmax[N][21],n,m,lg[N],bl[N],ans;
vector<pair<int,int> >G[N];
struct node
{
	int x,y,z;
}a[N];

bool Cmp(node x,node y)
{
	return x.z<y.z;
}

int gf(int k)
{
	return (fa[k]==k)?k:(fa[k]=gf(fa[k]));
}

void dfs(int k,int fa,int val)
{
	dep[k]=dep[fa]+1;
	gmax[k][0]=val;gfa[k][0]=fa;
	for (int i=1;i<=17;i++)
	  gfa[k][i]=gfa[gfa[k][i-1]][i-1];
	for (int i=1;i<=17;i++)
	  gmax[k][i]=max(gmax[k][i-1],gmax[ gfa[k][i-1]][i-1]);
	for (int i=0;i<G[k].size();i++)
	  if (G[k][i].first!=fa)
	    dfs(G[k][i].first,k,G[k][i].second);
}

int getmax(int x,int y)
{
	int res=INT_MIN;
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=17;i>=0;i--)
		if (dep[gfa[x][i]]>dep[y]) res=max(res,gmax[x][i]),x=gfa[x][i];
	if (dep[x]>dep[y]) res=max(res,gmax[x][0]),x=gfa[x][0];
	if (x==y) return res;
	for (int i=17;i>=0;i--)
	  if (gfa[x][i]!=gfa[y][i]) res=max(res,max(gmax[x][i],gmax[y][i])),x=gfa[x][i],y=gfa[y][i];
	res=max(res,max(gmax[x][0],gmax[y][0]));
	return res;
}

signed main()
{
	n=read(),m=read();
	lg[1]=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=m;i++) a[i].x=read(),a[i].y=read(),a[i].z=read();
	sort(a+1,a+m+1,Cmp);
	for (int i=1;i<=m;i++)
	  if (gf(a[i].x)!=gf(a[i].y))
		{
			G[a[i].x].push_back(make_pair(a[i].y,a[i].z));
			G[a[i].y].push_back(make_pair(a[i].x,a[i].z));
			fa[fa[a[i].x]]=fa[a[i].y];
			bl[i]=1;
		}
	gfa[1][0]=1,gmax[1][0]=INT_MIN;
	dfs(1,0,INT_MIN);
	for (int i=1;i<=m;i++)
	  if (!bl[i])
	  	ans+=max(0ll,getmax(a[i].x,a[i].y)+1-a[i].z);
	writeln(ans);
}