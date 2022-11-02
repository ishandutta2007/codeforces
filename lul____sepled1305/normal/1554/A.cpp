#include <iostream>
using namespace std;
 
int main() {
	int T; cin>>T;
	while(T--) {
		long long ans = 0;
		int last = 0;
		int n; cin>>n;
		for(int i=0;i<n;i++) {
			int a;
			cin>>a;
			ans = max(ans,1LL*a*last);
			last = a;
		}
		cout<<ans<<endl;
	}
	return 0;
}