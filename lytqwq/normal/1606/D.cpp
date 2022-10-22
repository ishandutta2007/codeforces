#include<bits/stdc++.h>
using namespace std;
#define PI pair<int,int>
#define mp make_pair
const int N=500010;
int t,n,m,vis[N];
PI c[N];
vector<int> a[N],maxn[N],minn[N],maxn2[N],minn2[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			a[i].clear();
			a[i].push_back(0);
			for(int o=1;o<=m;o++){
				int x;
				scanf("%d",&x);
				a[i].push_back(x);
			}
			c[i].first=a[i][1];
			c[i].second=i;
		}
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			minn[i].clear();
			minn[i].push_back(1e6);
			for(int o=1;o<=m;o++){
				minn[i].push_back(min(minn[i][o-1],a[i][o])); 
			}
			minn2[i].clear();
			for(int o=0;o<=m+1;o++)minn2[i].push_back(1e6);
			for(int o=m;o>=1;o--){
				minn2[i][o]=min(minn2[i][o+1],a[i][o]);
			}
			maxn[i].clear();
			maxn[i].push_back(0);
			for(int o=1;o<=m;o++){
				maxn[i].push_back(max(maxn[i][o-1],a[i][o])); 
			}
			maxn2[i].clear();
			for(int o=0;o<=m+1;o++)maxn2[i].push_back(0);
			for(int o=m;o>=1;o--){
				maxn2[i][o]=max(maxn2[i][o+1],a[i][o]);
			}
		}
		for(int i=2;i<=n;i++){
			for(int o=1;o<=m;o++){
				maxn[c[i].second][o]=max(maxn[c[i-1].second][o],maxn[c[i].second][o]);
			}
			for(int o=1;o<=m;o++){
				minn2[c[i].second][o]=min(minn2[c[i-1].second][o],minn2[c[i].second][o]);
			}
		}
		for(int i=n-1;i>=1;i--){
			for(int o=1;o<=m;o++){
				minn[c[i].second][o]=min(minn[c[i+1].second][o],minn[c[i].second][o]);
			}
			for(int o=1;o<=m;o++){
				maxn2[c[i].second][o]=max(maxn2[c[i+1].second][o],maxn2[c[i].second][o]);
			}
		}
		int ok=0;
		for(int o=1;o<=m-1;o++){
			for(int i=1;i<=n-1;i++){//blue
				if(maxn[c[i].second][o]<minn[c[i+1].second][o]&&maxn2[c[i+1].second][o+1]<minn2[c[i].second][o+1]){
					printf("YES\n");
					for(int p=1;p<=i;p++){
						vis[c[p].second]=1;
					}
					for(int p=i+1;p<=n;p++){
						vis[c[p].second]=2;
					}
					for(int p=1;p<=n;p++){
						if(vis[p]==1)printf("B");
						else printf("R");
					}
					printf(" %d\n",o);
					ok=1;
					break;
				}
			}
			if(ok)break;
		}
		if(ok==0){
			printf("NO\n");
		}
	}
	return 0;
}