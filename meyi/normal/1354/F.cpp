#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=81;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll ans,e[maxn][maxn],idx[maxn],idy[maxn],slack[maxn];
bool visx[maxn],visy[maxn];
int k,mchx[maxn],mchy[maxn],n,pre[maxn];
queue<int>q;
inline void aug(int p){
	int tmp;
	while(p){
		tmp=mchx[pre[p]];
		mchx[pre[p]]=p;
		mchy[p]=pre[p];
		p=tmp;
	}
}
inline void bfs(int s){
	while(q.size())q.pop();
	q.push(s);
	while(1){
		while(q.size()){
			int fr=q.front();q.pop();
			visx[fr]=true;
			for(ri to=1;to<=n;++to)
				if(!visy[to]){
					ll tmp=idx[fr]+idy[to]-e[fr][to];
					if(tmp<slack[to]){
						pre[to]=fr;
						slack[to]=tmp;
						if(!slack[to]){
							visy[to]=true;
							if(!mchy[to]){aug(to);return;}
							else q.push(mchy[to]);
						}
					}
				}
		}
		ll delta=inf;
		for(ri i=1;i<=n;++i)
			if(!visy[i])
				delta=min(delta,slack[i]);
		for(ri i=1;i<=n;++i){
			if(visx[i])idx[i]-=delta;
			if(visy[i])idy[i]+=delta;
			else slack[i]-=delta;
		}
		for(ri i=1;i<=n;++i)
			if(!visy[i]&&!slack[i]){
				visy[i]=true;
				if(!mchy[i]){aug(i);return;}
				else q.push(mchy[i]);
			}
	}
}
inline void KM(){
	memset(mchx,0,sizeof mchx);
	memset(mchy,0,sizeof mchy);
	memset(pre,0,sizeof pre);
	for(ri i=1;i<=n;++i){
		memset(slack,0x3f,sizeof slack);
		memset(visx,0,sizeof visx);
		memset(visy,0,sizeof visy);
		bfs(i);
	}
}
int t_case;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		memset(e,0,sizeof e);
		for(ri i=1,a,b;i<=n;++i){
			scanf("%d%d",&a,&b);
			for(ri j=1;j<k;++j)e[i][j]=a+1ll*b*(j-1);
			for(ri j=k;j<n;++j)e[i][j]=1ll*b*(k-1);
			e[i][n]=a+1ll*b*(k-1);
		}
		memset(idx,0,sizeof idx);
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=n;++j)
				idx[i]=max(idx[i],e[i][j]);
		KM();
		printf("%d\n",k+((n-k)<<1));
		for(ri i=1;i<=n;++i){
			printf("%d ",mchy[i]);
			if(k<=i&&i<n)printf("%d ",-mchy[i]);
		}
		printf("\n");
	}
	return 0;
}