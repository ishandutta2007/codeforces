#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
int T,a[N];
signed main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		int n; scanf("%lld",&n); 
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int mx=0,ans=0;
		for(int i=2;i<=n;i++){
			if(a[i]<a[i-1]){
				for(int j=60;j>=1;j--){
					if(a[i]+(1ll<<(j-1))<=a[i-1]){
						mx=max(mx,j); a[i]+=(1ll<<(j-1));
					}
				}
			}
		}
		printf("%lld\n",mx);
	}
	return 0;
}