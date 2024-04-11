#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int d[10001],s[10001],a[10001];
bool vis[20000001];
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&d[i]);
	scanf("%d%d",&x,&y);
	sort(d+1,d+m+1);
	for(int i=1;i<=m;i++)
		a[i]=1e9;
	s[++s[0]]=1;
	vis[1*1001]=1;
	a[1]=0;
	for(int z=1;;z++){
		queue<int>q;
		for(int i=1;i<=s[0];i++)
			q.push(s[i]*1001+x);
		s[0]=0;
		int ok=2e9;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			int o=u/1001,t=u%1001;
			if(t==0){
			//	printf("%d %d\n",o,z);
				s[++s[0]]=o;
				a[o]=z;
			}
			if(o==m)ok=min(ok,x-t);
			if(o!=1&&t>=d[o]-d[o-1]){
				int v=(o-1)*1001+t-(d[o]-d[o-1]);
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
			if(o!=m&&t>=d[o+1]-d[o]){
				int v=(o+1)*1001+t-(d[o+1]-d[o]);
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
		if(ok!=2e9){
			printf("%lld\n",1ll*(z-1)*(x+y)+ok);
			return 0;
		}
		if(s[0]==0)break;
	}
/*	long long ans=~0ull>>1;
	for(int i=1;i<=m;i++)
		if(a[i]!=1e9&&n-d[i]<=x&&1ll*a[i]*(x+y)+n-d[i]<ans)
			ans=1ll*a[i]*(x+y)+n-d[i];
	if(ans==~0ull>>1)printf("-1\n");
	else printf("%lld\n",ans);
*/
	printf("-1\n");
}