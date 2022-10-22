#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e3+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],b[maxn],c[maxn],n;
ll f[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		(a[i]?b[++*b]:c[++*c])=i;
	}
	memset(f,0x3f,sizeof f);
	memset(f[0],0,sizeof f[0]);
	for(ri i=1;i<=*b;++i)
		for(ri j=1;j<=*c;++j)
			ckmin(f[i][j],min(f[i][j-1],f[i-1][j-1]+abs(b[i]-c[j])));
	printf("%lld",f[*b][*c]);
	return 0;
}