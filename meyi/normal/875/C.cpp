#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
struct edge{
	int to,nxt;
}e[maxn<<2];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int clr,cnt,dfn[maxn],id[maxn],low[maxn],m,n;
bool vis[maxn];
stack<int>s;
void tarjan(int p){
	dfn[p]=low[p]=++cnt;
	vis[p]=true;
	s.push(p);
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!dfn[e[i].to])tarjan(e[i].to),low[p]=min(low[p],low[e[i].to]);
		else if(vis[e[i].to])low[p]=min(low[p],dfn[e[i].to]);
	if(dfn[p]==low[p]){
		++clr;
		ri k;
		do{
			k=s.top();s.pop();
			id[k]=clr;
			vis[k]=false;
		}while(k!=p);
	}
}
int ans[maxn],l[2],tmp[2][maxn];
int main(){
	scanf("%d%d",&n,&m);
	while(n--){
		ri now=n&1,pre=now^1;
		scanf("%d",l+now);
		for(ri i=1;i<=l[now];++i)scanf("%d",tmp[now]+i);
		for(ri i=1;i<=min(l[now],l[pre]);++i){
			if(tmp[now][i]!=tmp[pre][i]){
				ri id1=(tmp[now][i]-1)<<1,id2=(tmp[pre][i]-1)<<1;
				if(tmp[now][i]>tmp[pre][i])addedge(id2,id1),addedge(id1^1,id2^1);
				else addedge(id1^1,id1),addedge(id2,id2^1);
				break;
			}
			if(i==min(l[now],l[pre])&&l[now]<l[pre])return puts("No"),0;
		}
	}
	for(ri i=0;i<(m<<1);++i)
		if(!dfn[i])
			tarjan(i);
	for(ri i=0;i<m;++i){
		if(id[i<<1]==id[i<<1|1])return puts("No"),0;
		else if(id[i<<1]>id[i<<1|1])ans[++*ans]=i+1;
	}
	printf("Yes\n%d\n",*ans);
	for(ri i=1;i<=*ans;++i)printf("%d ",ans[i]);
	return 0;
}