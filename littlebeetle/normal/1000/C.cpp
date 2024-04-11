#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=400002;
int n,cnt,i,o;
ll l,r,s[N];
struct p{
	ll d;
	int t;
	bool operator<(const p &k)const{
		return k.d>d;
	}
}a[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%I64d%I64d",&l,&r);
		a[++cnt]=(p){l,1};
		a[++cnt]=(p){r+1,-1};
	}
	sort(a+1,a+cnt+1);
	for(i=1;i<=cnt;i++){
		s[o]+=a[i].d-a[i-1].d;
		o+=a[i].t;
	}
	for(i=1;i<=n;i++)
		printf("%I64d ",s[i]);
}