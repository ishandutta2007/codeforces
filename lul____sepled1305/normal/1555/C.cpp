#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while(T--) {
		int m; cin>>m;
		int v[2][m];
		for(int i=0;i<2;i++) {
			for(int j=0;j<m;j++) 
				cin>>v[i][j];
		}
		int sum1 = 0, sum2 = 0;
		for(int i=0;i<m;i++) {
			sum1 += v[0][i];
			sum2 += v[1][i];
		}
		int ans = 2e9;
		int cur1 = 0, cur2 = 0;
		for(int i=0;i<m;i++) {
			cur1 += v[0][i]; cur2 += v[1][i];
			//cout<<sum1<<' '<<sum2<<' '<<cur1<<' '<<cur2<<endl;
			ans = min(ans,max(sum1 - cur1, cur2 - v[1][i]));
		}
		cout<<ans<<endl;
	}
	return 0;
}