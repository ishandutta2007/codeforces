#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	ll h,hh,w,ww;
	scanf("%lld%lld%lld%lld",&w,&h,&ww,&hh);
	printf("%lld\n",4+(h+hh)*2+w+ww+abs(w-ww));
	return 0;
}