#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T; cin>>T;
	while(T--) {
		int ans = 0;
		int mix = 0, miy = 0, mx = 0, my = 0;
		int n; cin>>n;
		for(int i=0;i<n;i++) {
			int x,y; cin>>x>>y;
			mix = max(mix,-x);
			mx = max(mx,x);
			miy = max(miy,-y);
			my = max(my,y);
		}
		cout<<2*(mix+miy+mx+my)<<endl;
	}
	return 0;
}