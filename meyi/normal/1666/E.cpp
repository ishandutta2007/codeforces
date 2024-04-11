/*
um_nik  
um_nik 
um_nik 

 /oh/oh/oh
*/
#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],len,L,n,R;
inline bool check(int k){
	for(ri i=1,j=0;i<=n;++i){
		if((j+=k)>a[i+1])return false;
		ckmax(j,a[i]);
	}
	return true;
}
inline int half_mn(){
	ri l=1,r=1e9,ret=1e9;
	while(l<=r){
		ri mid=l+r>>1;
		if(check(mid))ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}
typedef pair<int,int> pii;
#define fi first
#define se second
pii f[maxn];
inline bool dp(int l,int r){
	for(ri i=1;i<=n;++i){
		f[i]={max(a[i],f[i-1].fi+l),min(a[i+1],f[i-1].se+r)};
		if(f[i].fi>f[i].se)return false;
	}
	return f[n].se==len;
}
inline int half_mx(){
	ri l=L,r=1e9,ret=L;
	while(l<=r){
		ri mid=l+r>>1;
		if(dp(L,mid))ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}
int ans[maxn];
int main(){
//	freopen("E.in","r",stdin);
	scanf("%d%d",&len,&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	a[n+1]=len;
	L=half_mn(),R=half_mx();
//	printf("%d %d\n",L,R);
	dp(L,R);
	ans[n]=len;
	for(ri i=n-1;i;--i){
		ri cur=f[i].fi+L;
		if(cur<=ans[i+1]&&cur+(R-L)>=ans[i+1])ans[i]=f[i].fi;
		else ans[i]=ans[i+1]-R;
	}
	for(ri i=1;i<=n;++i)printf("%d %d\n",ans[i-1],ans[i]);
	return 0;
}