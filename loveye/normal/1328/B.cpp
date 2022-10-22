#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int t,sum[N];
char s[N];
signed main() {
	cin >> t;
	for(int i = 1;i <= N-5;++i)
		s[i] = 'a';
	for(int i = 1;i <= N-5;++i)
		sum[i] = sum[i-1] + i;
	while(t--) {
		int n,k,a = 0,b = 0;
		cin >> n >> k;
		int p = lower_bound(sum+1,sum+n+1,k) - sum;
		a = n-p;
		k -= sum[p-1];
		b = n+1-k;
		s[a] = 'b',s[b] = 'b';s[n+1] = '\0';
		cout << s+1 << endl;
		s[a] = 'a',s[b] = 'a',s[n+1] = 'a';
	}
	return 0;
}