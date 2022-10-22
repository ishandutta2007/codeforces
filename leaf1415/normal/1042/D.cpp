#include <iostream>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, t;
llint a[200005];
llint s[200005];
P p[200005];
llint idx[200005];

llint bit[200005];
llint query(llint i){
	i++;
	llint ret = 0;
	while(i > 0){
		ret += bit[i];
		i -= i&(-i);
	}
	return ret;
}
void add(llint i, llint x){
	i++;
	while(i <= n+1){
		bit[i] += x;
		i += i&(-i);
	}
}

int main(void)
{
	cin >> n >> t;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	
	for(int i = 0; i <= n; i++) p[i] = make_pair(s[i], i);
	sort(p,p+n+1);
	for(int i = 0; i <= n; i++) idx[p[i].second] = i;
	sort(s, s+n+1);
	
	llint ans = 0;
	for(int i = n; i >= 0; i--){
		int pos = idx[i];
		int r = lower_bound(s, s+n+1, s[pos] + t) - s - 1;
		ans += query(r);
		add(pos, 1);
	}
	cout << ans << endl;
	
	return 0;
}