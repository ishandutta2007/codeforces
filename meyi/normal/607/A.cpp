#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=1e6+10,maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],ans,b[maxn],f[maxm],mx,n,pos[maxm];
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d%d",a+i,b+i),ckmax(mx,a[i]),pos[a[i]]=i;
	for(ri i=0;i<=mx;++i){
		if(pos[i]){
			if(b[pos[i]]>=i)f[i]=1;
			else f[i]=f[i-b[pos[i]]-1]+1;
		}
		else if(i)f[i]=f[i-1];
		ckmax(ans,f[i]);
	}
	printf("%d",n-ans);
	return 0;
}