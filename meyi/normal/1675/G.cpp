#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=310;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],f[maxn][maxn],m,n,pre[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),pre[i]=pre[i-1]+a[i];
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(ri k=m;~k;--k)
		for(ri i=0;i<n;++i)
			for(ri j=k;j<=m;++j)
				ckmin(f[i+1][j],f[i][j-k]+abs(j-pre[i+1]));
	printf("%d",f[n][m]);
	return 0;
}