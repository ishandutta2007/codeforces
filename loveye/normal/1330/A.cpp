#include<bits/stdc++.h>
using namespace std;
const int N = 305;
int t,n,a[N],ans,sum[N];
int cnt[N];
int main() {
	cin >> t;
	while(t--) {
		int res = 0,x;
		cin >> n >> x;
		for(int i = 1;i <= n;++i)
			cin >> a[i],cnt[a[i]] = 1;
		for(int i = 1;i <= n+x;++i)
			sum[i] = sum[i-1] + cnt[i];
		for(int i = n+x;i >= 1;--i)
			if(i - sum[i] <= x) {cout << i << endl;break;}
		for(int i = 1;i <= n+x;++i)
			sum[i] = 0,cnt[a[i]] = 0;
	}
	return 0;
}