#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, Q;
llint a[200005];
llint cnt[200005];
map<P, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> Q;
	
	llint need = 0, use = 0;
	for(int i = 1; i <= n; i++) need += a[i];
	
	llint s, t, u;
	for(int q = 0; q < Q; q++){
		cin >> s >> t >> u;
		if(mp.count(P(s, t))){
			llint x = mp[P(s, t)];
			cnt[x]--;
			if(cnt[x] < a[x]) use--;
		}
		if(u == 0) mp.erase(P(s, t));
		else{
			mp[P(s, t)] = u;
			cnt[u]++;
			if(cnt[u] <= a[u]) use++;
		}
		cout << need - use << "\n";
	}
	flush(cout);
	
	return 0;
}