#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll f[maxn];
inline void ins(int w,ll v){for(ri i=999999;i>=w;--i)ckmax(f[i],f[i-w]+v);}
int F[6],k,q;
signed main(){
	scanf("%d",&k),k=3*(k-1);
	for(ri i=0;i<6;++i)scanf("%d",F+i);
	for(ri i=1;i<1000000;++i){
		ri j=i,k=0;
		while(j){
			ri x=j%10;
			if(x==3||x==6||x==9)f[i]+=1ll*(x/3)*F[k];
			j/=10,++k;
		}
	}
	for(ri i=0,j=3;i<6;++i,j*=10){
		ri num=min(k,999999/j);
		for(ri l=1;l<=num;num-=l,l<<=1)ins(l*j,1ll*l*F[i]);
		if(num)ins(num*j,1ll*num*F[i]);
	}
	scanf("%d",&q);
	while(q--){
		ri x;
		scanf("%d",&x);
		printf("%lld\n",f[x]);
	}
	return 0;
}