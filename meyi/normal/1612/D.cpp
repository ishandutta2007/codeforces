#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
ll x;
inline bool check(ll a,ll b){
	if(!b)return false;
	if(a>=x&&(a-x)%b==0)return true;
	return check(b,a%b);
}
int t_case;
ll a,b;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld%lld%lld",&a,&b,&x);
		puts(check(a,b)?"YES":"NO");
	}
	return 0;
}