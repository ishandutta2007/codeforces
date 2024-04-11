#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=10005;
int n,k,c[MAXN];
int lst[MAXN],pre[MAXN],a[MAXN];
bool vis[MAXN];
int ans[MAXN][2];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n*k; i++){
		scanf("%d",c+i);
		pre[i]=lst[c[i]];
		lst[c[i]]=i;
	}
	int cnt=n;
	while(cnt){
		int p=0;
		for(int i=1; i<=n*k; i++){
			if(!vis[c[i]]&&pre[i]>p){
				vis[c[i]]=1;
				p=i;
				cnt--;
				ans[c[i]][0]=pre[i];
				ans[c[i]][1]=i;
			}
		}
	}
	for(int i=1; i<=n; i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}