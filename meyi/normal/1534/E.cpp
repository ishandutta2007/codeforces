#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int inf=0x3f3f3f3f,maxn=510;
int a[maxn],ans,dis[maxn],k,n,pre[maxn],val[maxn],x;
queue<int>q;
void dfs(int p){
	if(~pre[p])dfs(pre[p]);
	else return;
	printf("? ");
	for(ri cnt1=val[p],cnt2=k-val[p],i=1;cnt1||cnt2;++i){
		if(a[i]){
			if(cnt1)a[i]^=1,--cnt1,printf("%d ",i);
		}
		else{
			if(cnt2)a[i]^=1,--cnt2,printf("%d ",i);
		}
	}
	printf("\n");
	fflush(stdout);
	scanf("%d",&x);
	ans^=x;
}
int main(){
	scanf("%d%d",&n,&k);
	memset(dis,0x3f,sizeof dis);
	dis[0]=0;
	memset(pre,-1,sizeof pre);
	q.push(0);
	while(q.size()){
		ri now=q.front();q.pop();
		for(ri i=0;i<=k;++i)
			if(i<=now&&(k-i)<=(n-now)){
				ri nxt=now-i+(k-i);
				if(nxt>0&&nxt<=n&&dis[now]+1<dis[nxt]){
					dis[nxt]=dis[now]+1;
					pre[nxt]=now;
					val[nxt]=i;
					q.push(nxt);
				}
			}
	}
	if(dis[n]==inf){
		puts("-1");
		fflush(stdout);
		return 0;
	}
	dfs(n);
	printf("! %d",ans);
	fflush(stdout);
	return 0;
}