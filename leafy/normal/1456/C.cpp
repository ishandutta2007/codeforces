#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=5e5+5;
int n,k;
int a[N];
ll s1[N],s2[N];
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s1[i]=s1[i-1]+a[i],s2[i]=s2[i-1]+1ll*a[i]*(i-1);
	ll ans=s2[n],cnt=0,s=0;
	for(int i=1,t=0;i<=n;i++){
		t++;s+=cnt*a[i];
		ans=max(ans,s+s2[n]-s2[i]-(i-cnt-1)*(s1[n]-s1[i]));
		if(t==k+1) t=0,cnt++;
	}
	printf("%lld",ans);
	return 0;
}