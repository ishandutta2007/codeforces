#include<cstdio>
#include<map>
using namespace std;

int x[200001],y[200001];
map<int,int>a[200001],b[200001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
			a[i].clear();
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&y[i]);
			b[i].clear();
		}
		for(int i=1;i<=k;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			int p=lower_bound(x+1,x+n+1,u)-x,
				q=lower_bound(y+1,y+m+1,v)-y;
			if(x[p]==u&&y[q]==v)continue;
			else if(x[p]==u){
				b[q][p]++;
			}
			else a[p][q]++;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(map<int,int>::iterator ii=a[i].begin();ii!=a[i].end();ii++){
				ans+=sum*ii->second;
				sum+=ii->second;
			}
		}
		for(int i=1;i<=m;i++){
			int sum=0;
			for(map<int,int>::iterator ii=b[i].begin();ii!=b[i].end();ii++){
				ans+=sum*ii->second;
				sum+=ii->second;
			}
		}
		printf("%lld\n",ans);
	}
}