#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
typedef multiset<int>::iterator MIT;

const int N = 100005, mod = 1e9 + 7;
int n, x, y;
PII e[N];
multiset<int> s;
LL ans = 0;
int main(){
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i <= n; i++){
		int l, r; scanf("%d%d", &l, &r);
		e[i] = make_pair(l, r);
		ans = (ans + (LL)(r - l) * y) % mod;
	}
	
	sort(e + 1, e + 1 + n);
	s.insert(e[1].second);
	(ans += x) %= mod;
	for(int i = 2; i <= n; i++) {
		MIT it = s.lower_bound(e[i].first);
		if(it != s.begin()) --it;
		int last = *it;
		if(last < e[i].first && (LL)(e[i].first - last) * y < x) {
			s.erase(it);
			s.insert(e[i].second);
			ans = (ans + (LL)(e[i].first - last) * y) % mod;
		}else{
			s.insert(e[i].second);
			(ans += x) %= mod;
		}
	}
	printf("%lld\n", ans);
    return 0;
}