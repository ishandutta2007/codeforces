#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,INF=0x3fffffff;
const ll Inf=1ll<<60;
int n,m,a[MAXN],b[MAXN*3],ty[MAXN*3];
struct node{
	int l,r;
}seg[MAXN];
ll f[MAXN],g[MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	//freopen("in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),b[i]=a[i];
		sort(a+1,a+n+1);
		//for(int i=1; i<=n; i++) printf("%d ",a[i]); puts("");
		*b=n;
		int ans=0;
		f[1]=0;
		for(int i=1; i<=m; i++){
			scanf("%d%d",&seg[i].l,&seg[i].r);
			if(seg[i].l>a[n]){
				ans=max(ans,seg[i].l-a[n]);
				continue;
			}
			if(seg[i].r<a[1]){
				f[1]=max(f[1],1ll*a[1]-seg[i].r);
				continue;
			}
			if(a[lower_bound(a+1,a+n+1,seg[i].l)-a]<=seg[i].r) continue;
			//printf("%d %d\n",seg[i].l,seg[i].r);
			b[++*b]=seg[i].l;
			//b[++*b]=seg[i].r;
		}
		sort(b+1,b+*b+1);
		*b=unique(b+1,b+*b+1)-b-1;
		for(int i=1; i<=*b+1; i++)
			ty[i]=INF;
		for(int i=1; i<=m; i++){
			if(seg[i].r<a[1]||seg[i].l>a[n]||a[lower_bound(a+1,a+n+1,seg[i].l)-a]<=seg[i].r) continue;
			int t=lower_bound(b+1,b+*b+1,seg[i].l)-b-1;
			ty[t]=min(ty[t],seg[i].r);
		}
		for(int i=*b; i; i--)
			ty[i]=min(ty[i],ty[i+1]);
		g[1]=f[1]*2;
		//printf("%d\n",f[1]);
		for(int i=1,j=1; i<=n; i++){
			//printf("%d a %d\n",i,a[i]);
			if(i==1){
				while(b[j]<a[i]) j++;
				continue;
			}
			if(a[i]==a[i-1]){
				f[i]=g[i]=f[i-1];
				continue;
			}
			f[i]=g[i]=Inf;
			while(b[j]<a[i]){
				f[i]=min(f[i],min(f[i-1]+2ll*(b[j]-a[i-1]),g[i-1]+b[j]-a[i-1])+max(0,a[i]-ty[j]));
				g[i]=min(g[i],min(f[i-1]+2ll*(b[j]-a[i-1]),g[i-1]+b[j]-a[i-1])+2ll*max(0,a[i]-ty[j]));
				//printf("b %d f %lld\n",b[j],ty[j]);
				j++;
			}
			//printf("%d f %lld g %lld\n",a[i],f[i],g[i]);
		}
		//printf("%d\n",ans);
		printf("%lld\n",min(f[n]+ans*2ll,g[n]+ans));
		//break;
	}
	return 0;
}