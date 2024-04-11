#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],b[maxn],l,m,n,s[maxn];
inline bool check(int k){
	for(ri i=1;i<=n;++i)s[i]=s[i-1]+(a[i]<k?-1:1);
	for(ri i=l,mn=0;i<=n;++i){
		mn=min(mn,s[i-l]);
		if(s[i]>mn)return true;
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&l);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-b-1;
	for(ri i=1;i<=n;++i)a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	int ans=1,l=1,r=m;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",b[ans]);
	return 0;
}