#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,q; cin>>n>>q;
	int a[n];
	int c[2] = {0,0};
	for(int i=0;i<n;i++)
		cin>>a[i], c[a[i]]++;
	for(int i=0;i<q;i++) {
		int t,x; cin>>t>>x;
		if(t==1) {
			x--;
			a[x] = 1-a[x];
			c[a[x]]++;
			c[1-a[x]]--;
		}
		else {
			if(c[1] >= x)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}
	return 0;
}