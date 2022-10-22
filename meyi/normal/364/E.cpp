#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2510;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline char gc(){
	char ch;
	while(!isdigit(ch=getchar()));
	return ch;
}
bool a[maxn][maxn];
int k,l[7],m,n,pre[maxn][maxn],r[7];
ll ans;
inline int get_sum(int x,int y,int xx,int yy){
	if(x>xx||y>yy)return 0;
	return pre[xx][yy]-pre[x-1][yy]-pre[xx][y-1]+pre[x-1][y-1];
}
void solve(int x,int y,int xx,int yy){
	if(x>xx||y>yy||get_sum(x,y,xx,yy)<k)return;
	if(x==xx&&y==yy){
		if(a[x][y]==k)++ans;
		return;
	}
	if(xx-x>=yy-y){
		ri mid=x+xx>>1;
		for(ri i=y;i<=yy;++i){
			for(ri kk=0;kk<=k;++kk)l[kk]=x-1,r[kk]=xx+1;
			for(ri j=i;j<=yy;++j){
				for(ri kk=0;kk<=k;++kk){
					while(l[kk]<=mid&&get_sum(l[kk]+1,i,mid,j)>kk)++l[kk];
					while(r[kk]>mid&&get_sum(mid+1,i,r[kk]-1,j)>kk)--r[kk];
				}
				if(l[k]==mid||r[k]==mid+1)break;
				if(k){
					ans+=1ll*(mid-l[0])*(r[k]-r[k-1]);
					for(ri kk=1;kk<k;++kk)ans+=1ll*(l[kk-1]-l[kk])*(r[k-kk]-r[(k-kk)-1]);
					ans+=1ll*(l[k-1]-l[k])*(r[0]-(mid+1));
				}
				else ans+=1ll*(mid-l[0])*(r[0]-(mid+1));
			}
		}
		solve(x,y,mid,yy),solve(mid+1,y,xx,yy);
	}
	else{
		ri mid=y+yy>>1;
		for(ri i=x;i<=xx;++i){
			for(ri kk=0;kk<=k;++kk)l[kk]=y-1,r[kk]=yy+1;
			for(ri j=i;j<=xx;++j){
				for(ri kk=0;kk<=k;++kk){
					while(l[kk]<=mid&&get_sum(i,l[kk]+1,j,mid)>kk)++l[kk];
					while(r[kk]>mid&&get_sum(i,mid+1,j,r[kk]-1)>kk)--r[kk];
				}
				if(l[k]==mid||r[k]==mid+1)break;
				if(k){
					ans+=1ll*(mid-l[0])*(r[k]-r[k-1]);
					for(ri kk=1;kk<k;++kk)ans+=1ll*(l[kk-1]-l[kk])*(r[k-kk]-r[(k-kk)-1]);
					ans+=1ll*(l[k-1]-l[k])*(r[0]-(mid+1));
				}
				else ans+=1ll*(mid-l[0])*(r[0]-(mid+1));
			}
		}
		solve(x,y,xx,mid),solve(x,mid+1,xx,yy);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(a[i][j]=gc()^48);
	solve(1,1,n,m);
	printf("%lld",ans);
	return 0;
}