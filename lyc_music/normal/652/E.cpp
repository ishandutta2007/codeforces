//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 300005

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

int U,V,top,tim,n,m,x,y,z,bs[N],val[N],zhan[N],dfn[N],low[N],head[N],H[N],cnt,Cnt,scc,ans;

struct
{
	int from,to,val,nx;
}e[N<<1],E[N<<1];

void tarjan(int k,int fa)
{
    dfn[k]=low[k]=++tim;
    zhan[++top]=k;
    for (int i=head[k];i;i=e[i].nx)
    {
    	if (!dfn[e[i].to])
    	{
    		tarjan(e[i].to,k);
    		low[k]=min(low[k],low[e[i].to]);
    	} else
    	if (e[i].to!=fa) low[k]=min(low[k],dfn[e[i].to]);
    }
    if (dfn[k]==low[k])
    {
    	scc++;
    	do
    	{
    		bs[zhan[top]]=scc;
    		top--;
    	}while (zhan[top+1]!=k);
    }
}

void ad1(int x,int y,int z)
{
	E[++Cnt].from=x;
	E[Cnt].to=y;
	E[Cnt].nx=H[x];
	E[Cnt].val=z;
	H[x]=Cnt;
}

void ad(int x,int y,int z)
{
	e[++cnt].from=x;
	e[cnt].to=y;
	e[cnt].nx=head[x];
	e[cnt].val=z;
	head[x]=cnt;
}

int dfs(int k,int fa)
{
	//cout<<k<<" "<<fa<<endl;
	int Ret=0,pp=0;
	if (k==bs[V]) {ans|=val[k];return 1;}
	for (int i=H[k];i;i=E[i].nx)
	if (E[i].to!=fa)
	{
		pp=dfs(E[i].to,k);
		if (pp) 
		{
		    ans|=E[i].val,ans|=val[k];
		    //cout<<"!"<<E[i].from<<" "<<E[i].to<<endl;
		    return pp;
		}
	}
	return Ret;
}

signed main()
{
    n=read(),m=read();
    for (int i=1;i<=m;i++)
    {
    	x=read(),y=read(),z=read();
    	ad(x,y,z);
    	ad(y,x,z);
    }
    tarjan(1,0);
    for (int i=1;i<=2*m;i+=2)
      if (bs[e[i].from]==bs[e[i].to])
      {
      	val[bs[e[i].to]]=max(val[bs[e[i].to]],e[i].val);
      } else ad1(bs[e[i].from],bs[e[i].to],e[i].val),ad1(bs[e[i].to],bs[e[i].from],e[i].val);
    U=read(),V=read();
    dfs(bs[U],0);
    if (ans) puts("YES"); else puts("NO");
}