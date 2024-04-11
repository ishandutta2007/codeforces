#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
int n,a,r,m,h[MAXN];
ll s[MAXN];
ll f(ll k){
	int w=lower_bound(h+1,h+n+1,k)-h-1;
	ll s1=w*k-s[w],s2=s[n]-s[w]-(n-w)*k;
	ll res=0;
	if(s1>s2) res=s2*m+(s1-s2)*a;
	else res=s1*m+(s2-s1)*r;
	return res;
}
ll ans;
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d%d%d%d",&n,&a,&r,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",h+i);
	sort(h+1,h+n+1);
	for(int i=1; i<=n; i++)
		s[i]=s[i-1]+h[i];
	m=min(m,a+r);
	int l=0,r=1e9;
	while(r-l>10){
		int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
		if(f(lmid)>f(rmid)) l=lmid;
		else r=rmid;
		//printf("l %d r %d\n",l,r);
	}
	ans=f(l);
	for(int i=l; i<=r; i++)
		ans=min(ans,f(i));
	printf("%lld\n",ans);
	return 0;
}