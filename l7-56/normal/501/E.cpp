#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll maxn = 1e5 + 10;
ll a[maxn],n,num[maxn],num0[maxn],num1[maxn],ans;

int main() {
//	freopen(".in", "r", stdin); freopen(".out", "w", stdout);
	scanf("%lld", &n);
	for(ll i = 1; i <= n; ++i) scanf("%lld", &a[i]), num[a[i]]++;
	
	ll cnt_odd = 0;
	for(ll i = 1; i <= 100000; ++i) cnt_odd += (num[i] & 1);
	if(cnt_odd > 1) return printf("0\n"), 0;
	
	ll al = 1, ar = n;
	while(al < ar && a[al] == a[ar]) ++al, --ar;
	if(al >= ar) return printf("%lld\n", n * (n + 1) / 2), 0;
	ans = al * al;
	
	ll bl = (n + 1) / 2, br = bl + !(n & 1);
	while(bl > al && a[bl] == a[br]) --bl, ++br;
	for(ll i = al; i <= bl; ++i) num0[a[i]]++;
	for(ll i = br; i <= ar; ++i) num1[a[i]]++;
	bool flag = 1;
	for(ll i = 1; i <= 100000; ++i)
		if(num0[i] != num1[i]) { flag = 0; break; }
	if(flag) {
		ans += al * (ar - bl) * 2;
		printf("%lld\n", ans);
		return 0;
	}
	
	ll pos, cnt = 0;
	for(ll i = 1; i <= 100000; ++i) num[i] = 0;
	for(ll i = al; i <= ar; ++i) num[a[i]]++;
	for(ll i = 1; i <= 100000; ++i) cnt += (bool)num[i];
	for(ll i = al; i <= ar; ++i) {
		if(num[a[i]] >= 1 && num[a[i]] <= 2) --cnt;
		num[a[i]] -= 2;
		if(cnt == 0) {
			pos = i;
			break;
		}
	}
	ans += al * (ar - pos);
	
	cnt = 0;
	for(ll i = 1; i <= 100000; ++i) num[i] = 0;
	for(ll i = ar; i >= al; --i) num[a[i]]++;
	for(ll i = 1; i <= 100000; ++i) cnt += (bool)num[i];
	for(ll i = ar; i >= al; --i) {
		if(num[a[i]] >= 1 && num[a[i]] <= 2) --cnt;
		num[a[i]] -= 2;
		if(cnt == 0) {
			pos = i;
			break;
		}
	}
	ans += (n - ar + 1) * (pos - al);
	printf("%lld\n", ans);
	return 0;
}