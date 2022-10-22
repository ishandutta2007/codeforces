#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,a[MAXN],b[MAXN];
int pre[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
int cnt[MAXN];
ll ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++)
			scanf("%d",b+i);
		for(int i=1; i<=n; i++)
			pre[i]=i,cnt[i]=0;
		for(int i=1; i<=n; i++)
			pre[fnd(a[i])]=fnd(b[i]);
		for(int i=1; i<=n; i++)
			cnt[fnd(i)]++;
		int tot=0;
		for(int i=1; i<=n; i++)
			if(cnt[i]&1) tot++;
		ans=0;
		for(int i=1; i<=(n-tot)/2; i++){
			ans-=i;
			ans+=n-i+1;
		}
		ans*=2;
		printf("%lld\n",ans);
	}
	return 0;
}