#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5,INF = 0x3f3f3f3f;
int n,a[N],sum,minsum,ans;
int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1;i <= n;++i)
		cin >> a[i];
	for(int k = -30;k <= 30;++k) {
		int ok = 0;
		for(int i = 1;i <= n;++i)
			if(a[i] == k) ok = 1;
		if(!ok) continue;
		sum = 0,minsum = 0;
		for(int i = 1;i <= n;++i)
			if(a[i] > k) sum = 0,minsum = 0;
			else sum += a[i],ans = max(ans,sum - minsum - k),minsum = min(sum,minsum);
	}
	cout << ans << endl;
	return 0;
}