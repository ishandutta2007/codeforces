#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=205;
int n,p[MAXN],q[MAXN];
int pre[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
int ans[MAXN];
int to[MAXN];
bool vis[MAXN];
int main(){
	//freopen("in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d",p+i);
			pre[i]=i;
			q[p[i]]=i;
			to[i]=0;
			vis[i]=0;
		}
		for(int i=1; i<=n; i++)
			pre[fnd(i)]=fnd(p[i]);
		for(int i=1; i<n; i++)
			if(fnd(i)!=fnd(i+1)){
				vis[i]=1;
				pre[fnd(i)]=fnd(i+1);
			}
		for(int i=1; i<=n; i++){
			if(!vis[i]) continue;
			int j=i;
			while(vis[j]) j++;
			for(int k=i; k<j; k++)
				to[q[k]]=k+1;
			to[q[j]]=i;
			//printf("i %d j %d\n",i,j);
			i=j;
		}
		ans[n]=1;
		for(int i=n; i>1; i--)
			if(to[ans[i]]) ans[i-1]=to[ans[i]];
			else ans[i-1]=p[ans[i]];
		for(int i=1; i<=n; i++)
			printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}