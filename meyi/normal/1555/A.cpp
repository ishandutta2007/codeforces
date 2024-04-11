#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,t_case;
ll n;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%lld",&n);
		if(n<=6)puts("15");
		else if(n&1)printf("%lld\n",(n+1)/2*5);
		else printf("%lld\n",n/2*5);
	}
	return 0;
}