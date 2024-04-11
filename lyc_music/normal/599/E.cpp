//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long
#define N 105
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


int n,m,q,dp[15][1ll<<15];
struct 
{
	int a,b,c;
}b[N];

struct
{
	int u,v;
}a[N];

int dfs(int k,int z)
{
//	cout<<k-1<<" "<<z<<" "<<dp[k][z]<<endl;
	if (~dp[k][z]) return dp[k][z];
	int p=z-(1<<(k-1)),l=1;
	while (!((1<<(l-1))&p)) l++;
	dp[k][z]=0;
	for (int NX=p;NX;NX=(NX-1)&p)
	{               
		bool bl=0;
		int op=0,nx=0;
		if(!(NX&(1<<(l-1)))) continue;
		for (int i=1;i<=q;i++)
		  if (b[i].c==k&&(NX&(1<<(b[i].a-1)))&&(NX&(1<<(b[i].b-1)))) 
		  	bl=1;
		for (int i=1;i<=q;i++)
		  if ((NX&(1<<(b[i].c-1)))&&(!(NX&(1<<(b[i].a-1)))||!(NX&(1<<(b[i].b-1)))))
		  	bl=1;
		for (int i=1;i<=m;i++)
		{
			if (a[i].u==k||a[i].v==k) continue;
			if ((NX&(1<<(a[i].u-1)))&&(!(NX&(1<<(a[i].v-1))))||(!(NX&(1<<(a[i].u-1))))&&(NX&(1<<(a[i].v-1)))) bl=1;
		}
		for (int i=1;i<=m;i++)
		{
			if (a[i].u==k&&(NX&(1<<(a[i].v-1)))) ++op,nx=a[i].v; else if (a[i].v==k&&(NX&(1<<(a[i].u-1)))) ++op,nx=a[i].u;
		}
//		cout<<NX<<" "<<bl<<" "<<op<<" "<<nx<<endl;
		if (bl) continue;
//		cout<<"!"<<k-1<<" "<<op<<" "<<nx-1<<endl;
		if (op==0)
		{
			for (int i=1;i<=n;i++)
			  if (NX&(1<<(i-1))) 
			    dp[k][z]+=dfs(i,NX)*dfs(k,p^NX^(1<<(k-1)));
		} else if (op==1) 
		{
			dp[k][z]+=dfs(nx,NX)*dfs(k,p^NX^(1<<(k-1)));
		}
	}
	return dp[k][z];
}
		
signed main()
{
	n=read(),m=read(),q=read();
	memset(dp,-1,sizeof(dp));
	for (int i=1;i<=m;i++)
	{
		a[i].u=read(),a[i].v=read();
	}
	for (int i=1;i<=q;i++)
	{
		b[i].a=read(),b[i].b=read(),b[i].c=read();
	}
	for (int i=1;i<=n;i++) dp[i][1<<(i-1)]=1;
	dfs(1,(1<<n)-1);
	writeln(dp[1][(1<<n)-1]);
}