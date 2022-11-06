#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define N 300009
using namespace std;

int n,b[N],c[N],nc[N]; bool vis[N]; ll a[N],ans[N];
void gg(){ puts("No"); exit(0); }
bool check(ll *ans){
	ll now=ans[1]; int i;
	for (i=2; i<=n; i++){
		ll tmp=now^ans[i];
		if (tmp<=now) gg(); now=tmp;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	int i,j; ll mx=0;
	for (i=1; i<=n; i++){
		scanf("%lld",&a[i]); mx=max(mx,a[i]);
	}
	for (i=60; i>=0; i--) if (mx>>i&1) break;
	int cnt=0;
	for (; i>=0; i--){
		int pt=0;
		for (j=1; j<=n; j++) if (!vis[j] && (a[j]>>i&1)) b[++pt]=j;
		int now=0,np=0;
		for (j=1; j<=cnt; j++){
			if (!now && pt){
				//cerr<<j<<' '<<b[pt]<<endl;
				nc[++np]=b[pt--]; now^=1;
			}
			nc[++np]=c[j]; now^=(a[c[j]]>>i&1);
		}
		if (!now && pt) nc[++np]=b[pt--];
		for (j=1; j<=np; j++){
			c[j]=nc[j]; vis[c[j]]=1;
		}
		if (pt) gg();
		//cerr<<i<<endl;
		cnt=np;
		//for (j=1; j<=cnt; j++) cerr<<a[c[j]]<<' ';puts("");
	}
	for (i=1; i<=n; i++) ans[i]=a[c[i]];
	if (check(ans)){
		puts("Yes");
		for (i=1; i<=n; i++) printf("%lld%c",ans[i],i<n?' ':'\n');
	} else gg();
	return 0;
}