#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e6+5,P=998244353;
int T,n,k,v[N],tmp[N];
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)tmp[(i+k-1)%n+1]=v[i];
	for(int i=1;i<=n;i++)v[i]=tmp[i];
	int ans=1;
	for(int i=1;i<=n;i++)
		if(v[i]==-1)ans=1ll*ans*i%P;
		else if(v[i]==0)ans=1ll*ans*min(k+1,i)%P;
		else if(v[i]+k>=i)ans=0;
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}