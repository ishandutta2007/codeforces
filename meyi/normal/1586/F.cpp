#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int ans,k,n;
int main(){
	scanf("%d%d",&n,&k);
	ans=(int)ceil(log(n)/log(k));
	printf("%d\n",ans);
	for(ri i=0;i<n;++i)
		for(ri j=i+1;j<n;++j){
			ri x=i,y=j,z=0;
			while(x!=y)x/=k,y/=k,++z;
			printf("%d ",z);
		}
}