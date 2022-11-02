#include <iostream>
using namespace std;

int main() {
	int T; cin>>T;
	while(T--) {
		long long ans = -1e18;
		int n,k; cin>>n>>k;
		int v[n];
		for(int i=0;i<n;i++) {
			cin>>v[i];
		}
		for(int i=n-1;i>=0;i--) {
			for(int j=i-1;j>=0;j--) {
				if(1LL*(j+1)*(i+1) < ans)
					break;
				ans = max(ans,1LL*(j+1)*(i+1)-1LL*k*(v[i] | v[j]));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}