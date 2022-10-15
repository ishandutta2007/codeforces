//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
#define N 200005
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

int m,now,n,u,v,len,p[N],dis[N],dist[N],ans,ans1,cnt,head[N];

queue<int>q;

struct
{
	int to,nx;
}e[N<<1];


void ad(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}

void bfs(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(dist,0x3f,sizeof(dist));
	dis[s]=0,dist[s]=1;
	q.push(s);
	while (!q.empty())
	{
		now=q.front();
		q.pop();
		for (int i=head[now];i;i=e[i].nx)
		  if (dis[now]+1<dis[e[i].to])
		  {
		  	dis[e[i].to]=dis[now]+1,dist[e[i].to]=1;q.push(e[i].to);
		  } else if (dis[now]+1==dis[e[i].to]) dist[e[i].to]++;
	}	
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		u=read(),v=read();
		ad(v,u);
	}
	len=read();
	for (int i=1;i<=len;i++)
	  p[i]=read();
	bfs(p[len]);
	for (int i=1;i<len;i++)
	{
		if (dis[p[i]]!=dis[p[i+1]]+1) ans++;
		else
		{
			if (dist[p[i]]>1) ans1++;
		}
	}
	writesp(ans),writeln(ans1+ans);
}