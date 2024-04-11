#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int maxn=1e5+10;
int a[maxn],k,l,n,q,r;
unsigned long long s[maxn];
int main(){
	scanf("%d%d%d",&n,&q,&k);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=n;++i)s[i]=a[i+1]-a[i-1]-2+s[i-1];
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%llu\n",s[r-1]-s[l]+(a[l+1]-2)+(k-a[r-1]-1));
	}
	return 0;
}