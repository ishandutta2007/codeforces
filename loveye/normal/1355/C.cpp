#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,d;
long long ans;
long long sum(int l,int r) {
	if(l > r) return 0;
	return (r-l+1) * (long long)(l + r) / 2;
}
inline long long cnt(int x) {
	int l = max(c-x+1,b),r = min(d-x+1,c);
	return sum(l+x-c,r+x-c) + (r < c ? (d-c+1) * (c-max(r,b-1)) : 0ll);
}
signed main() {
	cin >> a >> b >> c >> d;
	for(int i = a;i <= b;++i)
		ans += cnt(i);
	cout << ans << endl;
	return 0;
}