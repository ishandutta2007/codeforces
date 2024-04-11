#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int t;
int n;
long long a[maxn];
map<long long,int> m;
int main() {
	scanf("%d",&t);
	while(t--) {
		m.clear();
		scanf("%d",&n);
		long long s=0;
		for(int i=0;i<n;i++) {
			scanf("%lld",&a[i]);
			s=s+a[i];
		}
		long long ans=0;
		for(int i=0;i<n;i++) {
			ans=ans+m[a[i]*n];
			m[2*s-a[i]*n]+=1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}