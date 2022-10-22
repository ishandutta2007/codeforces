#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int t;
long long n;
int a[maxn];
int b[maxn];
long long ca[maxn];
long long cb[maxn];
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%lld",&n);
		for(int i=0;i<n;i++) {
			int u,v;
			scanf("%d %d",&u,&v);
			ca[u]+=1;
			cb[v]+=1;
			a[i]=u;
			b[i]=v;
		}
		long long ans=n*(n-1)*(n-2)/6;
		for(int i=0;i<n;i++) {
			ans=ans-(ca[a[i]]-1)*(cb[b[i]]-1);
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) {
			ca[i]=cb[i]=0;
		}
	}
	return 0;
}