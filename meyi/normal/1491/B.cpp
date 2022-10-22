#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a[maxn],ans,n,t,u,v;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&u,&v);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ans=INT_MAX;
		for(ri i=2;i<=n;++i){
			if(abs(a[i]-a[i-1])>1){
				ans=0;
				break;
			}
			if(a[i]==a[i-1]&&(i==n||a[i]==a[i+1]))ans=min(ans,min(v<<1,u+v));
			else ans=min(u,v);
		}
		printf("%d\n",ans);
	}
	return 0;
}