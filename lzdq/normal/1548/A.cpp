#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,q;
int cnt[MAXN],ans;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		cnt[u]++;
	}
	for(int i=1; i<=n; i++)
		if(!cnt[i]) ans++;
	scanf("%d",&q);
	while(q--){
		int op,u,v;
		scanf("%d",&op);
		if(op==3){
			printf("%d\n",ans);
			continue;
		}
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		if(op==1){
			cnt[u]++;
			if(cnt[u]==1) ans--;
		}else{
			cnt[u]--;
			if(!cnt[u]) ans++;
		}
	}
	return 0;
}