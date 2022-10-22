#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,t_case;
ll n,x;
inline ll calc(ll k){
	if((k-1)%4==0)return 1+((k-1)>>1)*2;
	else return calc(k-1)+((k-1)%4==3?k:-k);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld",&x,&n);
		printf("%lld\n",x+((x&1)?calc(n):-calc(n)));
	}
	return 0;
}