#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=1e5+5,M=34005;
#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,a[maxn],in[maxn],x,y;
vector<int>e[maxn];queue<int>q;
bool topsort()
{
	int s=0;
	for(int i=1;i<=n;i++)if(in[i]<=0)q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();s++;
		for(auto i:e[x]){in[i]--;if(!in[i])q.push(i);}
	}
	if(s==n)return true;
	return false;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)x=read(),y=read(),in[y]++,e[x].pb(y);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)a[j]=in[j];
		in[i]--;
		if(topsort())puts("YES"),exit(0);in[i]++;
		for(int j=1;j<=n;j++)in[j]=a[j];
	}
	puts("NO");
 	return 0;
}