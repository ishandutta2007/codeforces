#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
typedef pair<int,int> pr;
#define mkp make_pair
int n,m;
int all[MAXN],tot;
vector<int> a[MAXN];
ll ans;
int sum[MAXN],cnt[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			int x;
			scanf("%d",&x);
			a[i].push_back(x);
			all[++tot]=x;
		}
	sort(all+1,all+tot+1);
	tot=unique(all+1,all+tot+1)-all-1;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			a[i][j]=lower_bound(all+1,all+tot+1,a[i][j])-all;
			sum[a[i][j]]++;
		}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			ans+=1ll*i*(cnt[a[i][j]]-(sum[a[i][j]]-cnt[a[i][j]]-1));
			cnt[a[i][j]]++;
		}
	memset(cnt,0,sizeof(cnt));
	for(int j=0; j<m; j++)
		for(int i=0; i<n; i++){
			ans+=1ll*j*(cnt[a[i][j]]-(sum[a[i][j]]-cnt[a[i][j]]-1));
			cnt[a[i][j]]++;
		}
	printf("%lld\n",ans);
	return 0;
}