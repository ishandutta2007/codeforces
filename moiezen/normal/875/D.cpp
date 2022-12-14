#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define N 200005
int n,a[N];
int tp,stk[N],l[N],r[N];
int bitl[N][32],bitr[N][32];
int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	tp=0;
	per(i,n,1){
		while((tp)&&(a[stk[tp]]<=a[i])) tp--;
		if(tp) r[i]=stk[tp]-1;else r[i]=n;stk[++tp]=i;
	}
	tp=0;
	rep(i,1,n){
		while((tp)&&(a[stk[tp]]<a[i])) tp--;
		l[i]=stk[tp]+1;stk[++tp]=i;
	}
	rep(d,0,30){
		bitl[0][d]=0;
		rep(i,1,n) if(a[i]&(1<<d)) bitl[i][d]=i;else bitl[i][d]=bitl[i-1][d];
		bitr[n+1][d]=n+1;
		per(i,n,1) if(a[i]&(1<<d)) bitr[i][d]=i;else bitr[i][d]=bitr[i+1][d];
	}
	ll ans=0;
	rep(i,1,n){
		int pl=l[i],pr=r[i];
		rep(d,0,30) if(!(a[i]&(1<<d))){
			pl=std::max(pl,bitl[i-1][d]+1);
			pr=std::min(pr,bitr[i+1][d]-1);
		}
		ans-=1ll*(i-pl+1)*(pr-i+1);
		ans+=1ll*(i-l[i]+1)*(r[i]-i+1);
	}
	printf("%lld\n",ans);
}