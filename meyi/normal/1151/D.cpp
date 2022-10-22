#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct node{
	int a,b;
	inline bool operator<(const node &k)const{
		return b-a<k.b-k.a;
	}
}a[maxn];
int n;
ll ans;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d%d",&a[i].a,&a[i].b);
	sort(a+1,a+n+1);
	for(ri i=1;i<=n;++i)ans+=1ll*a[i].a*(i-1)+1ll*a[i].b*(n-i);
	printf("%lld",ans);
	return 0;
}