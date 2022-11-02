#include <bits/stdc++.h>
using namespace std;

int recur(int n, int m, int k) {
	//cout<<n<<' '<<m<<' '<<k<<endl;
	if(m < n)
		return 0;
	if(n == 0)
		return m+1;
	int l = 0;
	for(;l<=30;l++) {
		if(pow(2,l) > m-pow(2,k))
			break;
	}
	l--;
	if(pow(2,k) <= n) {
		int ans = recur(n-pow(2,k),m-pow(2,k),l);
		if(ans == 1<<k)
			ans *= 2;
		return ans;
	}
	return pow(2,k) + recur(n,m-pow(2,k),l);
}

int main() {
	int T; cin>>T;
	while(T--) {
		int n,m; cin>>n>>m;
		int k=0;
		for(;k<=30;k++) {
			if(pow(2,k) > m)
				break;
		}
		k--;
		cout<<recur(n,m,k)<<endl;
	}
	return 0;
}