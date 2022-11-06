//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
#define N 500010
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

int n,m,x,y,now,bl,b[N],vis[N],val[N];
vector<int>G[N];
struct node
{
	int i,j;
}a[N];

bool Cmp(node x,node y)
{
	return x.j<y.j;
}

signed main()
{
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i=1;i<=n;i++) a[i].i=i,a[i].j=read();
	for (int i=1;i<=n;i++) val[a[i].i]=a[i].j;
	sort(a+1,a+n+1,Cmp);
	for (int i=1;i<=n;i++)
	{
		now=a[i].i;
		vis[now]=1;bl=1;
		for (int j=0;j<G[now].size();j++)
		  if (vis[G[now][j]])
		  {
		  	b[val[G[now][j]]]=1;
		  }
		for (int i=1;i<val[now];i++)
		  if (!b[i])
		  {
		  	bl=0;
		  	break;
		  }
		if (!bl) return puts("-1"),0;
		if (b[val[now]]) return puts("-1"),0;
		for (int j=0;j<G[now].size();j++)
		  if (vis[G[now][j]])
		  {
		  	b[val[G[now][j]]]=0;
		  }
	}
	for (int i=1;i<=n;i++) writesp(a[i].i);
}