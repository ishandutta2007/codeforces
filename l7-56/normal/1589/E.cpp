#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 3e5 + 10;
ll a[maxn],T,n;
map <ll, ll> mp; 

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		mp.clear();
		mp[0] = 1;
		ll d = 0, ans = 0;
		for(int i = 1; i <= n; ++i) {
			d += a[i] * (i % 2 == 0 ? -1 : 1);
			if(i & 1)
				while(!mp.empty() && (--mp.end()) -> first > d) mp.erase(--mp.end());
			else
				while(!mp.empty() && (mp.begin()) -> first < d) mp.erase(mp.begin());
			auto it = mp.find(d);
			if(it != mp.end()) ans += it -> second;
			mp[d]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}