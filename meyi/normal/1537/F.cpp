#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
const int maxn=2e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int b[maxn],m,n,v[maxn],t,t_case;
bool flag;
ll sum,tot;
void dfs(int p,int k){
	b[p]=k;
	sum+=(k?v[p]:-v[p]);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(~b[e[i].to])flag|=(b[p]==b[e[i].to]);
		else dfs(e[i].to,k^1);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		memset(b,-1,sizeof b);
		memset(hd,0,sizeof hd);
		flag=len=sum=tot=0;
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i)scanf("%d",v+i);
		for(ri i=1;i<=n;++i)scanf("%d",&t),v[i]-=t,tot+=v[i];
		while(m--){
			ri x,y;
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		if(tot&1){puts("NO");continue;}
		dfs(1,0);
		puts(flag?"YES":sum?"NO":"YES");
	}
	return 0;
}