#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	// your code goes here
	int T; cin>>T;
	while(T--) {
		int n; cin>>n;
		int a[n];
		int bk = n-1;
		for(int i=n+1;i>=0;i--) {
			int cur = i*i;
			if(cur > 2*bk)
				continue;
			int ss = cur - bk;
			//We now put bk at ss
			int ff = bk;
			for(int i=ss;i<=bk;i++) {
				a[i] = ff;
				ff--;
			}
			bk = ff;
		}
		for(int i=0;i<n;i++)
			cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}