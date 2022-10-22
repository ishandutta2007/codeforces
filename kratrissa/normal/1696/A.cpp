#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,m,z,a[N],ans;
void solve(){
	scanf("%d%d",&n,&z);ans=0;
	for(int i=1;i<=n;i++)scanf("%d",&m),ans=max(ans,z|m);
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}