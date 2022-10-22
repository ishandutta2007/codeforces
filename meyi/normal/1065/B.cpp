#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
ll m;
int n;
int main(){
	scanf("%d%lld",&n,&m);
	for(ri i=0;;++i)
		if(1ll*i*(i-1)/2>=m)
			return printf("%lld %d",max(n-m*2,0ll),n-i),0;
}