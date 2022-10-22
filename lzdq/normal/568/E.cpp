#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
using namespace std;
const int MAXN=1e5+5;
int n,m;
int a[MAXN],b[MAXN],ans[MAXN];
int f[MAXN][2];
int tot,g[MAXN],pos[MAXN];
vector<int> vec[MAXN];
bool vis[MAXN];
vector<int> tmp;
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1; i<=m; i++)
		scanf("%d",b+i);
	sort(b+1,b+m+1);
	for(int i=1; i<=n; i++){
		if(~a[i]){
			int w=lower_bound(g+1,g+tot+1,a[i])-g-1;
			f[i][0]=w+1;
			f[i][1]=pos[w];
			if(w==tot) tot++;
			g[w+1]=a[i];
			pos[w+1]=i;
			vec[f[i][0]].push_back(i);
			//printf("%d f %d from %d\n",i,f[i][0],f[i][1]);
		}else{
			if(g[tot]<b[m]) tot++,g[tot]=b[m],pos[tot]=i;
			for(int j=m,k=tot; j; j--){
				while(g[k]>=b[j]) k--;
				g[k+1]=b[j];
				pos[k+1]=i;
			}
		}
		ans[i]=a[i];
	}
	//printf("tot %d\n",tot);
	int u=pos[tot],v=g[tot];
	while(tot){
		//printf("tot %d u %d v %d\n",tot,u,v);
		if(~a[u]){
			u=f[u][1];
			if(a[u]==-1) v=b[lower_bound(b+1,b+m+1,v)-b-1];
			else v=a[u];
		}else{
			ans[u]=v;
			if(tot==1) break;
			vis[lower_bound(b+1,b+m+1,v)-b]=1;
			int w=-1;
			for(int i:vec[tot-1]) {
				//printf("i %d\n",i);
				if(i>u) break;
				if(a[i]<v){
					w=i;
					break;
				}
			}
			if(~w) u=w,v=a[w];
			else{
				//puts("fuck");
				do u--;
				while(~a[u]);
				v=b[lower_bound(b+1,b+m+1,v)-b-1];
			}
		}
		tot--;
	}
		//printf("tot %d u %d v %d\n",tot,u,v);
	for(int i=1; i<=m; i++)
		if(!vis[i]) tmp.push_back(b[i]);
	for(int i=1; i<=n; i++)
		if(ans[i]==-1) ans[i]=tmp.back(),tmp.pop_back();
	for(int i=1; i<=n; i++)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}