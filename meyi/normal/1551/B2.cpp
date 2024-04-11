#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct node{
	int val,id;
	inline bool operator<(const node &k)const{
		return val<k.val;
	}
}a[maxn];
int ans[maxn],cnt[maxn],k,m,n,t_case;
bool vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		for(ri i=1;i<=n;++i)cnt[i]=vis[i]=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",&a[i].val),a[i].id=i;
			++cnt[a[i].val];
		}
		for(ri i=1;i<=n;++i)
			if(cnt[i]>=k)
				cnt[i]=0,vis[i]=true;
		for(ri i=1;i<=n;++i)
			if(vis[a[i].val])
				ans[i]=(++cnt[a[i].val]<=k?cnt[a[i].val]:0),a[i].val=0;
		sort(a+1,a+n+1);
		for(ri i=1;i<=n;){
			if(!a[i].val){
				++i;
				continue;
			}
			if(i+k-1>n){
				while(i<=n)ans[a[i].id]=0,++i;
				break;
			}
			for(ri j=i;j<=i+k-1;++j)ans[a[j].id]=j-i+1;
			ri nxt=i+k;
			while(nxt<=n&&a[i].val==a[nxt].val)ans[a[nxt].id]=0,++nxt;
			i=nxt;
		}
		for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}