#include <cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 200005
int n,dis,leaf,cnt[N],l[N],r[N],L,R;
int pl[N],pr[N],sh;
int main(){
	scanf("%d%d%d",&n,&dis,&leaf);
	pl[0]=pr[0]=1;
	rpt(i,1,dis) scanf("%d",&cnt[i]),pl[i]=pr[i-1]+1,pr[i]=pr[i-1]+cnt[i];
	rpt(i,1,dis-1){
		r[i]=cnt[i]-1;
		if(cnt[i]<=cnt[i+1]) l[i]=0;else l[i]=cnt[i]-cnt[i+1];
	}
//	rpt(i,1,dis-1) printf("%d %d %d %d\n",l[i],r[i],pl[i],pr[i]);
	L=R=0;leaf-=cnt[dis];
	rpt(i,1,n-1) L+=l[i],R+=r[i];
	if(leaf<L||leaf>R) return printf("-1"),0;
	printf("%d\n",n);
	leaf-=L;
	rpt(i,pl[1],pr[1]) printf("%d %d\n",i,1);
	rpt(i,1,dis-1){
		if(leaf>=r[i]-l[i]) sh=r[i]-l[i];else sh=leaf;
		leaf-=sh;
		if(cnt[i]<=cnt[i+1]){
			rpt(j,1,cnt[i]-sh) printf("%d %d\n",pl[i+1]+j-1,pl[i]+j-1);
			rpt(j,1,cnt[i+1]-cnt[i]+sh) printf("%d %d\n",cnt[i]-sh+pl[i+1]+j-1,pl[i]);
		}
		else{
			rpt(j,1,cnt[i+1]-sh) printf("%d %d\n",pl[i+1]+j-1,pl[i]+j-1);
			rpt(j,1,sh) printf("%d %d\n",cnt[i+1]-sh+pl[i+1]+j-1,pl[i]);
		}
	}
}