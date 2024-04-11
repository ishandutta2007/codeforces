#include<bits/stdc++.h> 
#define int long long
#define rep(i,a,b) for(register int i=a;i<=b;i++)
using namespace std;
const int N=200009;

int n,f[N],p[N],cnt,ans[N];

struct node{int id,val;}a[N];
bool cmp(const node&a,const node&b) {
	return a.val<b.val;
}

signed main() {
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld",&a[i].val), a[i].id=i;
	sort(a+1,a+n+1,cmp);
	rep(i,1,n) {
		f[i]=0x3f3f3f3f;
		rep(j,max(0ll,i-5),i-3)
			if(f[j]+a[i].val-a[j+1].val<f[i])
				f[i]=f[j]+a[i].val-a[j+1].val,p[i]=j;
	}
	int x=n;
	while(x) {
		++cnt;
		rep(i,p[x]+1,x) ans[a[i].id]=cnt;
		x=p[x];
	}
	printf("%lld %lld\n",f[n],cnt);
	rep(i,1,n) printf("%lld ",ans[i]);
	return 0;
}