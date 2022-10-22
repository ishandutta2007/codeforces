#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int t_case;
ll n,t,x;
inline ll sum(ll k){
	if(k<1)return 0;
	return k*(k+1)/2;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld%lld",&n,&x,&t);
		ll k=min(n-1,t/x);
		printf("%lld\n",k*n-sum(k));
	}
	return 0;
}