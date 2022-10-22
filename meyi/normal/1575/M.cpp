#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2010;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll a[maxn][maxn],f[maxn],ans;
int m,n;
char s[maxn][maxn];
void solve(int l,int r,int L,int R,int k){
	if(l>r||L>R)return;
	ri mid=l+r>>1,pos=0;
	ll tmp=1145141919810ll;
	for(ri i=L;i<=R;++i){
		ll val=a[k][i]+(mid-i)*(mid-i);
		if(val<tmp)pos=i,tmp=val;
	}
	f[mid]=tmp;
	solve(l,mid-1,L,pos,k);
	solve(mid+1,r,pos,R,k);
}
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=0;i<=n;++i){
		scanf("%s",s[i]);
		for(ri j=0;j<=m;++j)s[i][j]^=48;
	}
	memset(a,0x3f,sizeof a);
	for(ri i=0;i<=m;++i){
		ll lst=-114514;
		for(ri j=0;j<=n;++j){
			if(s[j][i])lst=j;
			ckmin(a[j][i],(lst-j)*(lst-j));
		}
		lst=114514;
		for(ri j=n;~j;--j){
			if(s[j][i])lst=j;
			ckmin(a[j][i],(lst-j)*(lst-j));
		}
	}
	for(ri i=0;i<=n;++i){
		memset(f,0x3f,sizeof f);
		solve(0,m,0,m,i);
		for(ri j=0;j<=m;++j)ans+=f[j];
	}
	printf("%lld",ans);
	return 0;
}