#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	int y,k,f,next;
}a[200010];
int first[510],len;
int d[510],flow[510],pre[510],l[510];
int sp,tp,_MAX=1<<30;
bool v[510];
queue<int> z;
char c[510],s[510];
int next[510];
int _Min(int x,int y){return x<y?x:y;}
void ins(int x,int y,int k,int f)
{
	a[++len].y=y;a[len].k=k;a[len].f=f;
	a[len].next=first[x];first[x]=len;
	a[++len].y=x;a[len].k=0;a[len].f=-f;
	a[len].next=first[y];first[y]=len;
}
bool spfa()
{
	memset(d,63,sizeof(d));
	memset(pre,0,sizeof(pre));
	d[sp]=0;flow[sp]=_MAX;
	z.push(sp);v[sp]=1;
	int x,k,y;
	while(!z.empty())
	{
	  x=z.front();z.pop();v[x]=0;
	  for(k=first[x];k;k=a[k].next)
	  {
		y=a[k].y;
		if(a[k].k&&d[x]+a[k].f<d[y])
		{
		  d[y]=d[x]+a[k].f;
		  flow[y]=_Min(flow[x],a[k].k);
		  pre[y]=x;l[y]=k;
		  if(!v[y])
		  {
			z.push(y);
			v[y]=1;
		  }
		}
	  }
	}
	return pre[tp];
}
int MAX_FLOW()
{
	int ans=0,x;
	while(spfa())
	{
	  ans+=d[tp]*flow[tp];
	  for(x=tp;x!=sp;x=pre[x])
	  {
		a[l[x]].k-=flow[tp];
		a[l[x]^1].k+=flow[tp];
	  }
	}
	return ans;
}
int main()
{
	int T,n,m,i,j,x,k,K;
	scanf("%d",&n);
	scanf("%s",c+1);
	scanf("%d",&T);
	sp=0;tp=n+1;len=1;
	while(T--)
	{
	  scanf("%s%d",s+1,&K);
	  m=strlen(s+1);
	  next[1]=k=0;
	  for(i=2;i<=m;i++)
	  {
		while(k!=0&&s[k+1]!=s[i])k=next[k];
		if(s[k+1]==s[i])k++;
		next[i]=k;
	  }
	  k=0;
	  for(i=1;i<=n;i++)
	  {
		while(k!=0&&s[k+1]!=c[i])k=next[k];
		if(s[k+1]==c[i])k++;
		if(k==m)ins(i-m+1,i+1,1,-K);
	  }
	}
	scanf("%d",&x);
	ins(sp,1,x,0);
	for(i=1;i<=n;i++)ins(i,i+1,_MAX,0);
	printf("%d\n",-MAX_FLOW());
	return 0;
}