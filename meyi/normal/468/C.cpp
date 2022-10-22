#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const ll inf=1e18;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
ll a,p;
int main(){
	scanf("%lld",&a);
	p=inf%a*9%a*9%a;
	printf("%lld %lld",a-p,inf-1+a-p);
	return 0;
}