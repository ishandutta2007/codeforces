#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=6e3+10;
struct node{
	int x,y;
	inline bool operator<(const node &k)const{
		return x!=k.x?x<k.x:y<k.y;
	}
}a[maxn],tmp[maxn];
int n;
ll ans,cnt[4][maxn];
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	for(ri i=1;i+1<n;++i){
		for(ri j=0;j<4;++j)cnt[j][i]=0;
		for(ri j=i+1;j<=n;++j){
			tmp[j].x=(a[j].x-a[i].x)>>1,tmp[j].y=(a[j].y-a[i].y)>>1;
			for(ri k=0;k<4;++k)cnt[k][j]=cnt[k][j-1];
			++cnt[((tmp[j].x&1)<<1)|(tmp[j].y&1)][j];
		}
		for(ri j=i+1;j<n;++j){
			if((tmp[j].x&1)&&(tmp[j].y&1))ans+=cnt[0][n]-cnt[0][j]+cnt[3][n]-cnt[3][j];
			if(!(tmp[j].x&1)&&(tmp[j].y&1))ans+=cnt[0][n]-cnt[0][j]+cnt[1][n]-cnt[1][j];
			if((tmp[j].x&1)&&!(tmp[j].y&1))ans+=cnt[0][n]-cnt[0][j]+cnt[2][n]-cnt[2][j];	
			if(!(tmp[j].x&1)&&!(tmp[j].y&1))ans+=cnt[0][n]-cnt[0][j]+cnt[1][n]-cnt[1][j]+cnt[2][n]-cnt[2][j]+cnt[3][n]-cnt[3][j];
		}
	}
	printf("%lld",ans);
	return 0;
}