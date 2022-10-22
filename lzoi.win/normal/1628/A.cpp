#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
vector<int> b[MAXN];
int m,ans[MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=0; i<=n; i++)
			b[i].clear();
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),b[a[i]].push_back(i);
		for(int i=0; i<=n; i++)
			b[i].push_back(n+1);
		int l=1;
		m=0;
		while(l<=n){
			int x=0,r=l;
			while(x<=n){
				int w=lower_bound(b[x].begin(),b[x].end(),l)-b[x].begin();
				if(b[x][w]>n) break;
				r=max(r,b[x][w]);
				//printf("x %d r %d\n",x,r);
				x++;
			}
			ans[++m]=x;
			l=r+1;
		}
		printf("%d\n",m);
		for(int i=1; i<=m; i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}