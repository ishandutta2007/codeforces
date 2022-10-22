#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
struct city{
	int a,c;
	inline bool operator<(const city k)const{
		return a<k.a;
	}
}a[maxn];
int m,n;
ll ans;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d%d",&a[i].a,&a[i].c);
	sort(a+1,a+n+1);
	ans=a[1].c,m=a[1].a+a[1].c;
	for(ri i=2;i<=n;++i)ans+=a[i].c+max(0,a[i].a-m),m=max(a[i].a+a[i].c,m);
	printf("%lld",ans);
	return 0;
}