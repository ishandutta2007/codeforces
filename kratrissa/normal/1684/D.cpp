#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int read(){
	int res=0;char c=getchar();
	while(c<48)c=getchar();
	while(c>=48)res=res*10+c-48,c=getchar();
	return res;
}
int T,n,k,a[N];
void solve(){
	n=read(),k=read();ll ans=1ll*k*(2*n-k+1)/2;
	for(int i=1;i<=n;i++)a[i]=read(),ans+=a[i],a[i]+=i;
	sort(a+1,a+n+1);
	for(int i=n;i>n-k;i--)ans-=a[i];
	printf("%lld\n",ans);
}
int main(){
	T=read();
	while(T--)solve();
	return 0;
}