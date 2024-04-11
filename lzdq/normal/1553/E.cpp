#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
int n,m,cnt[MAXN],p[MAXN],ans[5];
int pre[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
bool Check(int k){
	for(int i=1; i<=n; i++)
		pre[i]=i;
	for(int i=1; i<=n; i++){
		int x=fnd(i<=k?n-k+i:i-k),y=fnd(p[i]);
		if(x!=y) pre[x]=y;
	}
	int res=0;
	for(int i=1; i<=n; i++)
		if(fnd(i)==i) res++;
	return n-res<=m;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			cnt[i]=0;
		for(int i=1; i<=n; i++)
			scanf("%d",p+i),cnt[(i-p[i]+n)%n]++;
		*ans=0;
		for(int i=0; i<n; i++)
			if(cnt[i]+2*m>=n&&Check(i)) ans[++*ans]=i;
		printf("%d ",*ans);
		for(int i=1; i<=*ans; i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}