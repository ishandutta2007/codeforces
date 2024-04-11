#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n;
string s;
vector<llint> vec[200005];
llint ans[200005];
multiset<P> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	
	S.insert(P(inf, inf));
	
	llint id = 1;
	for(int i = 0; i < n; i++){
		llint c = s[i]-'a';
		auto it = S.upper_bound(P(c, inf));
		if(it == S.begin()){
			ans[i] = id;
			S.insert(P(c, id));
			id++;
		}
		else{
			it--;
			//cout << i << " "<< it->first << " " << it->second << endl;
			llint p = it->second;
			ans[i] = p;
			S.insert(P(c, p));
			S.erase(it);
		}
	}
	cout << id-1 << endl;
	for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}