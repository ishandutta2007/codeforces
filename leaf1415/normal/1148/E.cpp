#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> E;

llint n;
llint id[300005];
llint s[300005], t[300005];
bool used[300005];
vector<P> vec;
vector<E> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) cin >> t[i];
	
	for(int i = 1; i <= n; i++) vec.push_back(P(s[i], i));
	sort(vec.begin(), vec.end());
	for(int i = 0; i < vec.size(); i++) id[i+1] = vec[i].second;
	
	sort(s+1, s+n+1), sort(t+1, t+n+1);
	
	llint sumS = 0, sumT = 0;
	for(int i = 1; i <= n; i++) sumS += s[i], sumT += t[i];
	if(sumS != sumT){
		cout << "NO" << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) s[i] -= sumS, t[i] -= sumT;
	
	llint r = 1;
	for(int i = 1; i <= n; i++){
		if(s[i] == t[i]) continue;
		if(s[i] > t[i]){
			cout << "NO" << endl;
			return 0;
		}
		while(s[r] <= t[r]) r++;
		llint d = min(t[i]-s[i], s[r]-t[r]);
		s[i] += d, s[r] -= d;
		ans.push_back(E(P(id[i], id[r]), d));
		if(s[i] < t[i]) i--;
	}
	
	cout << "YES" << endl;
	cout << (int)ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << "\n";
	}
	flush(cout);
	
	return 0;
}