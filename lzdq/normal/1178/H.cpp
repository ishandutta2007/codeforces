#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pr;
#define mkp make_pair
const int MAXN=4405,V=1e9,INF=0x3fffffff;
int n,a[MAXN],b[MAXN],all[MAXN],id[MAXN],ab[MAXN];
ll c[MAXN],mx[MAXN],ac[MAXN];
int p1[MAXN],p2[MAXN];
namespace Dinic{
	const int MAXN=8805,MAXM=4e4;
	int cntp,s,t;
	int cnte=1,h[MAXN],to[MAXM],nx[MAXM],ww[MAXM],cc[MAXM];
	inline void adde(int u,int v,int w,int c){
		cnte++;
		nx[cnte]=h[u];
		to[cnte]=v;
		ww[cnte]=w;
		cc[cnte]=c;
		h[u]=cnte;
	}
	inline void Adde(int u,int v,int w,int c=0){
		if(!u||!v) return ;
		adde(u,v,w,c);
		adde(v,u,0,-c);
	}
	queue<int> que;
	int dis[MAXN],cur[MAXN],flw[MAXN],pre[MAXN];
	bool inq[MAXN];
	bool Spfa(){
		que.push(s);
		memset(dis,0x3f,sizeof(dis));
		dis[s]=0;
		flw[s]=INF;
		flw[t]=0;
		while(!que.empty()){
			int u=que.front();
			que.pop();
			inq[u]=0;
			for(int i=h[u]; i; i=nx[i]){
				int v=to[i];
				if(ww[i]&&dis[v]>dis[u]+cc[i]){
					dis[v]=dis[u]+cc[i];
					flw[v]=min(flw[u],ww[i]);
					pre[v]=i;
					if(!inq[v]){
						inq[v]=1;
						que.push(v);
					}
				}
			}
		}
		return flw[t];
	}
	int Cost(int k){
		s=n*2+1;
		t=s+1;
		cntp=t;
		memset(mx,0,sizeof(mx));
		for(int i=1; i<=n*2; i++){
			c[i]=b[i]+1ll*k*a[i];
			mx[id[i]]=max(mx[id[i]],c[i]);
		}
		for(int i=1; i<=*all; i++)
			mx[i]=max(mx[i],mx[i-1]);
		for(int i=1; i<=n; i++)
			ab[i]=b[i+n];
		sort(ab+1,ab+n+1);
		*ab=unique(ab+1,ab+n+1)-ab-1;
		for(int i=1; i<=*ab; i++){
			p1[i]=++cntp;
			Adde(p1[i],p1[i-1],INF);
		}
		for(int i=1; i<=n; i++){
			int w=upper_bound(ab+1,ab+*ab+1,b[i])-ab-1;
			Adde(i,p1[w],1,1);
			w=lower_bound(ab+1,ab+*ab+1,b[i+n])-ab;
			Adde(p1[w],i+n,1);
			Adde(s,i,1);
			Adde(i+n,t,1);
		}
		for(int i=1; i<=n; i++)
			ac[i]=c[i+n];
		sort(ac+1,ac+n+1);
		*ac=unique(ac+1,ac+n+1)-ac-1;
		for(int i=1; i<=*ac; i++){
			p2[i]=++cntp;
			Adde(p2[i],p2[i-1],INF);
		}
		for(int i=1; i<=n; i++){
			int w=upper_bound(ac+1,ac+*ac+1,mx[id[i]])-ac-1;
			Adde(i,p2[w],1,2);
			w=upper_bound(ac+1,ac+*ac+1,c[i])-ac-1;
			Adde(i,p2[w],1,1);
			w=lower_bound(ac+1,ac+*ac+1,c[i+n])-ac;
			Adde(p2[w],i+n,1);
		}
		int res=0,f=0;
		while(Spfa()){
			f+=flw[t];
			res+=flw[t]*dis[t];
			int u=t;
			while(u!=s){
				int e=pre[u];
				ww[e]-=flw[t];
				ww[e^1]+=flw[t];
				u=to[e^1];
			}
		}
		return res;
	}
	bool Flow(int k){
		memset(mx,0,sizeof(mx));
		for(int i=1; i<=n*2; i++){
			c[i]=b[i]+1ll*k*a[i];
			mx[id[i]]=max(mx[id[i]],c[i]);
		}
		for(int i=1; i<=*all; i++)
			mx[i]=max(mx[i],mx[i-1]);
		for(int i=1; i<=n; i++)
			c[i]=mx[id[i]];
		sort(c+1,c+n+1);
		sort(c+n+1,c+n*2+1);
		for(int i=1; i<=n; i++)
			if(c[i]<c[i+n]) return 0;
		return 1;
	}
}
int main(){
	//freopen("deal.in","r",stdin);
	//freopen("deal.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n*2; i++)
		scanf("%d%d",a+i,b+i),all[i]=b[i];
	sort(all+1,all+n*2+1);
	*all=unique(all+1,all+n*2+1)-all-1;
	for(int i=1; i<=n*2; i++)
		id[i]=lower_bound(all+1,all+*all+1,b[i])-all;
	int l=0,r=V+1;
	while(l<r){
		int mid=l+r>>1;
		if(Dinic::Flow(mid)) r=mid;
		else l=mid+1;
	}
	if(l>V) puts("-1"),exit(0);
	printf("%d %d\n",l,Dinic::Cost(l));
	return 0;
}