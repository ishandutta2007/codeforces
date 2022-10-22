#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],b[maxn],bl,cnt[maxn],m,n,pre[maxn],suf[maxn],t_case;
inline int calc(int x){return x<1?1:((1+bool(x&(x-1)))<<__lg(x));}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
		sort(b+1,b+n+1);
		bl=unique(b+1,b+n+1)-b-1;
		clear(cnt,bl);
		for(ri i=1;i<=n;++i)++cnt[lower_bound(b+1,b+bl+1,a[i])-b];
		ri mx=__lg(n)+1;
		for(ri i=0,j=1,k=0;i<=mx;++i){
			while(j<=bl&&k+cnt[j]<=(1<<i))k+=cnt[j++];
			pre[i]=k;
		}
		for(ri i=0,j=bl,k=0;i<=mx;++i){
			while(j&&k+cnt[j]<=(1<<i))k+=cnt[j--];
			suf[i]=k;
		}
		ri ans=INT_MAX;
		for(ri i=0;i<=mx;++i)
			for(ri j=0;j<=mx;++j)
				ckmin(ans,calc(pre[i])+calc(suf[j])+calc(n-pre[i]-suf[j])-n);
		printf("%d\n",ans);
	}
	return 0;
}