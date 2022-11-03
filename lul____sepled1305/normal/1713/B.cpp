#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T; cin>>T;
	while(T--) {
		int n; cin>>n;
		int a[n];
		int mx = 0, idx = -1;
		for(int i=0;i<n;i++) {
			cin>>a[i];
			if(a[i] > mx) {
				mx = a[i];
				idx = i;
			}
		}
		bool pass = true;
		for(int i=idx;i>0;i--) {
			if(a[i] < a[i-1])
				pass = false;
		}
		for(int i=idx;i<n-1;i++) {
			if(a[i] < a[i+1])
				pass = false;
		}
		if(pass)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}