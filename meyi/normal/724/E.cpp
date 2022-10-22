#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e4+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll f[maxn];
int a[maxn],b[maxn],C,n;
int main(){
	scanf("%d%d",&n,&C);
	memset(f,0x3f,n+1<<3);
	f[0]=0;
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=n;++i)scanf("%d",b+i);
	for(ri i=1;i<=n;++i)
		for(ri j=i;~j;--j){
			f[j]+=a[i]+1ll*j*C;
			if(j)ckmin(f[j],f[j-1]+b[i]);
		}
	printf("%lld",*min_element(f,f+n+1));
	return 0;
}
/*
f[i][j] ijS
f[i][j]=min(f[i-1][j]+a[i]+j*C,f[i-1][j-1]+b[i])
*/