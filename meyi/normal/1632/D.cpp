#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],f[maxn],n;
int lg,lg2[maxn],st[(int)log2(maxn)+1][maxn];
inline void build_st(){
	for(ri i=1;i<=n;++i)lg2[i]=lg2[i-1]+((2<<lg2[i-1])==i),st[0][i]=a[i];
	lg=lg2[n];
	for(ri i=1;i<=lg;++i)
		for(ri j=1;j+(1<<i)-1<=n;++j)
			st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
inline int query(int l,int r){
	ri k=lg2[r-l+1];
	return __gcd(st[k][l],st[k][r-(1<<k)+1]);
}
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	build_st();
	for(ri i=1;i<=n;++i){
		f[i]=f[i-1];
		for(ri j=i;j>0;){
			ri g=query(j,i),now=j;
			for(ri k=lg;~k;--k)
				if(j>(1<<k)&&query(j-(1<<k),i)==g)
					j-=(1<<k);
			if(g<=i-j+1&&g>=i-now+1){
				f[i]=f[i-g]+1;
				break;
			}
			--j;
		}
		printf("%d ",f[i]);
	}
	return 0;
}