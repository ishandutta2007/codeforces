#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T; cin>>T;
	while(T--) {
		int n; cin>>n;
		int a[n], b[n];
		for(int i=0;i<n;i++) cin>>a[i], b[i] = 0;
		long long ans = 0, reduc = 0;
		for(int i=0;i<n;i++) {
			ans += max(a[i]-b[i]-1,0);
			for(int j=min(n-1,i+a[i]);j>i+1;j--) {
				b[j]++;
			}
			if(b[i] > a[i]-1)
				b[i+1] += (b[i]+1-a[i]);
		}
		cout<<ans-reduc<<endl;
	}
	return 0;
}