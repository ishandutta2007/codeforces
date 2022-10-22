#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
#define inf 1e9

using namespace std;
typedef pair<int, int> P;

P p[3];
set<P> ans;

int main(void)
{
	for(int i = 0; i < 3; i++) cin >> p[i].first >> p[i].second;
	sort(p, p+3);
	
	int mn = inf, mx = -inf;
	for(int i = 0; i < 3; i++){
		mn = min(mn, p[i].second);
		mx = max(mx, p[i].second);
	}
	int X = p[1].first;
	
	for(int i = mn; i <= mx; i++) ans.insert(make_pair(X, i));
	for(int i = p[0].first; i <= X; i++) ans.insert(make_pair(i, p[0].second));
	for(int i = p[2].first; i >= X; i--) ans.insert(make_pair(i, p[2].second));
	
	cout << ans.size() << endl;
	for(auto it = ans.begin(); it != ans.end(); it++){
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
	
	return 0;
}