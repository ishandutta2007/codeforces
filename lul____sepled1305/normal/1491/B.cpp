#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T; cin>>T;
	while(T--) {
		int n,u,v; cin>>n>>u>>v;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		bool all = true, con = true;
		for(int i=1;i<n;i++) {
			if(a[i] != a[i-1])
				all = false;
			if(abs(a[i]-a[i-1]) > 1)
				con = false;
		}
		if(all) {
			cout<<v+min(u,v)<<endl;
		}
		else if(con) {
			cout<<min(u,v)<<endl;
		}
		else
			cout<<0<<endl;
	}
	return 0;
}