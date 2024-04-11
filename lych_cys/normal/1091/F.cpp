#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define N 100009
using namespace std;

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int n,pre[N]; ll a[N]; char s[N];
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++){
		scanf("%lld",&a[i]); //a[i]*=2;
	}
	scanf("%s",s+1);
	ll ans=0;
	bool G=0,W=0; ll x=0,y=0;
	for (i=1; i<=n; i++) ans+=a[i]*(s[i]=='G'?3:(s[i]=='W'?2:1));
	for (i=1; i<=n; i++){
		if (s[i]=='G'){
			G=1; pre[i]=x; x=i;
		} else if (s[i]=='W'){
			W=1; pre[i]=y; y=i;
		} else{
			ll now=a[i],tmp;
			while (now>0){
				if (y){
					for (; y; y=pre[y]){
						tmp=min(now,a[y]);
						ans+=tmp*1;
						now-=tmp; a[y]-=tmp;
						if (!now) break;
					}
				} else if (x){
					for (; x; x=pre[x]){
						tmp=min(now,a[x]);
						ans+=tmp*2;
						now-=tmp; a[x]-=tmp;
						if (!now) break;
					}
				} else if (W){
					ans+=now*3; now=0;
				} else{
					ans+=now*5; now=0;
				}
			}
		}
	}
	for (i=n; i; i--) if (s[i]=='G' && a[i]){
		for (; y; y=pre[y]){
			if (y>i) continue;
			ll tmp=min(a[i],a[y]);
			ans-=tmp; a[i]-=tmp; a[y]-=tmp;
			if (!a[i]) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}