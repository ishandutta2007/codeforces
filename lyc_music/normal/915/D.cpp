//QwQcOrZ yyds!!!
#include<bits/stdc++.h>

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

int n,m,x,y,ru[10000],head[10000],cnt,vis[10000],N,ru1[10000];

queue<int>q;

struct
{
	int to,nx;
}e[100005];

void ad(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		x=read(),y=read();
		ad(x,y);
		ru[y]++;
	}
	for (int now=1;now<=n;now++)
	  if (ru[now])
	  {
	  	ru[now]--;cnt=0;
	  	for (int i=1;i<=n;i++)
	  	{
	  		ru1[i]=ru[i];
	  		if (ru1[i]==0) q.push(i);
	  		vis[i]=0;
	  	}
	  	while (!q.empty())
	  	{
	  		cnt++;
	  		N=q.front();
	  		q.pop();
	  		vis[N]=1;
	  		for (int i=head[N];i;i=e[i].nx)
	  		{
	  			ru1[e[i].to]--;
	  			if (ru1[e[i].to]==0) q.push(e[i].to);
	  		}
	  	}
	  	if (cnt==n) {puts("YES");return 0;}
	  	ru[now]++;
	  }
	puts("NO");
}