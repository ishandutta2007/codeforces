#include<bits/stdc++.h>
#define N 100005
#define mo 1000000007
#define int long long

using namespace std;

int T,n,ans,m,x,y,head[N],a[N],cnt,dep[N],size[N];


priority_queue <int,vector<int>,less<int> >q;

struct 
{
	int to,nx;
}e[N<<1];
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
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

void ad(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}

void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;size[k]=1;
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=fa)
	  {
	  	dfs(e[i].to,k);
	  	size[k]+=size[e[i].to];
	  }
}
void dfss(int k,int fa)
{
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=fa)
	  {
	  	q.push(size[e[i].to]*(n-size[e[i].to]));
	  	dfss(e[i].to,k);
	  }
}
signed main()
{
    scanf("%d",&T);
    while (T--)
    {
    	scanf("%d",&n);ans=0;cnt=0;
    	for (int i=1;i<=n;i++) head[i]=0;
    	for (int i=1;i<n;i++)
    	{
    		scanf("%d",&x);scanf("%d",&y);
    		ad(x,y);
    		ad(y,x);
    	}
    	scanf("%d",&m);
    	for (int i=1;i<=m;i++)
    	  scanf("%d",&a[i]);
    	dfs(1,0);
    	dfss(1,0);sort(a+1,a+m+1);
    	if (m>--n)
    	{
    		for (int i=n+1;i<=m;i++) (a[n]*=a[i])%=mo;
    		m=n;
    	}
    	while (!q.empty())
    	{
    		//cout<<"!"<<q.top()<<endl;
    		(ans+=(q.top()*max(1ll,a[m--]))%mo)%=mo;
    		if (m<0) m=0;
    		q.pop();
    	}
    	cout<<ans<<endl;
    }
}