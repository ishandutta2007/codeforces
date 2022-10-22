#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct node{
	int val,id;
	inline bool operator<(const node &k)const{
		return val<k.val;
	}
}a[maxn];
int bel[maxn],cnt,kl[maxn],kr[maxn],m,n,q;
inline bool in(int l,int k,int r){return l<=k&&k<=r;}
inline int query(int k){
	ri K=bel[k];
	for(ri i=kl[K];i<=kr[K];++i)
		if(a[i].id==k)
			return a[i].val;
	return -1;
}
inline int query(int l,int r,int v){
	ri L=bel[l],R=bel[r],ret=0;
	if(L==R){
		for(ri i=kl[L];i<=kr[R];++i)
			if(in(l,a[i].id,r)&&a[i].val<=v)
				++ret;
		return ret;
	}
	for(ri i=L+1;i<R;++i)ret+=upper_bound(a+kl[i],a+kr[i]+1,node{v,0})-(a+kl[i]);
	for(ri i=kl[L];i<=kr[L];++i)
		if(in(l,a[i].id,r)&&a[i].val<v)
			++ret;
	for(ri i=kl[R];i<=kr[R];++i)
		if(in(l,a[i].id,r)&&a[i].val<v)
			++ret;
	return ret;
}
inline void modify(int k,int v){
	ri K=bel[k];
	for(ri i=kl[K];i<=kr[K];++i)
		if(a[i].id==k){
			a[i].val=v;
			break;
		}
	sort(a+kl[K],a+kr[K]+1);
}
ll ans;
signed main(){
	scanf("%d%d",&n,&q);
	m=max((int)sqrt(n),2);
	for(ri i=1;i<=n;++i){
		a[i]={i,i};
		if(i%m==1)kr[cnt]=i-1,kl[++cnt]=i;
		bel[i]=cnt;
	}
	kr[cnt]=n;
	while(q--){
		ri x,y;
		scanf("%d%d",&x,&y);
		if(x!=y){
			if(x>y)swap(x,y);
			ri xv=query(x),yv=query(y);
			if(xv<yv)++ans;
			else --ans;
			if(x+1<y){
				ri len=y-x-1,tmp1=query(x+1,y-1,xv),tmp2=query(x+1,y-1,yv);
				ans-=tmp1+(len-tmp2);
				ans+=(len-tmp1)+tmp2;
			}
			modify(x,yv),modify(y,xv);
		}
		printf("%lld\n",ans);
	}
	return 0;
}