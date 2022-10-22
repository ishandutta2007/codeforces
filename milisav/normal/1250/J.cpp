#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int t;
int n;
int a[maxn];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(int i=2;i<=n+1;i++) scanf("%d",&a[i]);
		bool ok=true;
		long long cur=1;
		for(int i=2;i<=n+1 && ok;i++) {
			if(cur>1e9) break;
			cur=cur*i/__gcd(cur,1ll*i);
			if(a[i]%cur==0) ok=false;
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}