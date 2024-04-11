#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
const int maxn=400005,maxm=1200005;
int n,m,ee,Q,s,t,e=1,flg,flow;
int start[maxn],to[maxm],then[maxm],limit[maxm],dep[maxn],cur[maxn],vis[maxn],rec[maxn],res[maxn],xx[maxn],yy[maxn],match[maxn],hav[maxn],del[maxn];
long long sum;
queue<int>q;
vector<int>v[maxn];
inline void add(int x,int y,int z){
	then[++e]=start[x],start[x]=e,to[e]=y,limit[e]=z;
}
inline void addedge(int x,int y,int z){
	add(x,y,z),add(y,x,0);
}
int bfs(int s){
	for(int i=1;i<=t;i++)
		vis[i]=0,dep[i]=t+1,cur[i]=start[i];
	q.push(s),vis[s]=1,dep[s]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop(),vis[x]=0;
		for(int i=start[x];i;i=then[i]){
			int y=to[i];
			if(limit[i]&&dep[y]>dep[x]+1){
				dep[y]=dep[x]+1;
				if(vis[y]==0)
					q.push(y),vis[y]=1;
			}
		}
	}
	return dep[t]!=t+1;
}
int dfs(int x,int flw,int t){
	if(x==t){
		flow+=flw,flg=1;
		return flw;
	}
	int rst=flw;
	for(int i=cur[x];i;i=then[i]){
		cur[x]=i;
		int y=to[i];
		if(limit[i]&&dep[y]==dep[x]+1){
			int newflw=dfs(y,min(rst,limit[i]),t);
			if(newflw){
				rst-=newflw,limit[i]-=newflw,limit[i^1]+=newflw;
				if(rst==0)
					break;
			}
			else dep[y]=0;
		}
	}
	return flw-rst;
}
int Dinic(int s,int t){
	flow=0;
	while(bfs(s))
		for(flg=1;flg;)
			flg=0,dfs(s,1,t);
	return flow;
}
void get(int x){
	if(hav[x])
		return ;
	hav[x]=1;
//	printf("x=%d\n",x);
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i],k=match[y],z=xx[k]+yy[k]-y;
		if(del[y]==0&&del[z]==0)
			get(z);
	}
}
int find(int k){
	return hav[xx[k]]==0? xx[k]:yy[k];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&ee,&Q);
	s=n+m+1,t=n+m+2;
	for(int i=1;i<=n;i++)
		addedge(s,i,1);
	for(int i=1;i<=m;i++)
		addedge(n+i,t,1);
	for(int i=1,x,y;i<=ee;i++)
		scanf("%d%d",&x,&y),addedge(x,n+y,1),rec[i]=e,xx[i]=x,yy[i]=n+y,v[x].push_back(n+y),v[n+y].push_back(x);
	int now=0,ini=Dinic(s,t),tmp=0;
//	printf("ini=%d\n",ini);
	for(int i=1;i<=n+m;i++)
		vis[i]=0;
	for(int i=1;i<=ee;i++)
		if(limit[rec[i]]==1)
			res[++tmp]=i,vis[xx[i]]=vis[yy[i]]=1,match[xx[i]]=i,match[yy[i]]=i,sum+=i;
//			printf("match %d\n",i);
	for(int i=1;i<=n+m;i++)
		if(vis[i]==0)
			get(i);
	while(Q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			now++;
			int x=find(res[now]);
			del[x]=1,sum-=match[x];
			printf("1\n%d\n%lld\n",x>n? (-(x-n)):x,sum);
			fflush(stdout);
		}
		if(t==2){
			printf("%d\n",ini-now);
			for(int i=now+1;i<=ini;i++)
				printf("%d%c",res[i],i==ini? '\n':' ');
			fflush(stdout);
		}
	}
	return 0;
}