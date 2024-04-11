#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=4e5+10;
int a[maxn],m,n,t_case;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lg,lg2[maxn],st[(int)log2(maxn)+1][maxn];
inline void build_st(){
	for(ri i=1;i<=n*2;++i)lg2[i]=lg2[i-1]+((2<<lg2[i-1])==i),st[0][i]=a[i];
	lg=lg2[n*2];
	for(ri i=1;i<=lg;++i)
		for(ri j=1;j+(1<<(i-1))<=n*2;++j)
			st[i][j]=0;
	for(ri i=1;i<=lg;++i)
		for(ri j=1;j+(1<<(i-1))<=n*2;++j)
			st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
inline int query(int l,int r){
	ri k=lg2[r-l+1];
	return gcd(st[k][l],st[k][r-(1<<k)+1]);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri tmp=a[1];
		for(ri i=2;i<=n;++i)tmp=gcd(tmp,a[i]);
		for(ri i=1;i<=n;++i)a[i]/=tmp,a[i+n]=a[i];
		build_st();
		ri ans=0;
		for(ri i=1;i<=n;++i){
			if(a[i]==1)continue;
			ri l=i+1,r=n*2,ret=i;
			while(l<=r){
				ri mid=l+r>>1;
				if(query(i,mid)>1)ret=mid,l=mid+1;
				else r=mid-1;
			}
			ckmax(ans,ret-i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}