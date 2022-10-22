#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
int n,m,a[100001];
int main() {
	cin>>n>>m;int mx=0,i;ll s=0;
	for (i=1;i<=n;i++) cin>>a[i],s+=a[i],mx=max(mx,a[i]);
	sort(a+1,a+n+1);
	ll ans=0,mrr=0;
	for (i=1;i<=n;i++) {
		if (a[i]>mrr) ans++,mrr++;
		else ans++;
	}
	ans+=a[n]-mrr;
	printf("%I64d\n",s-ans);
}