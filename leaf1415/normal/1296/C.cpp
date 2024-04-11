#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint T, n;
string s;
P p[200005];
vector<pair<P, llint> > vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		cin >> s;
		s = "#" + s;
		for(int i = 1; i <= n; i++){
			p[i] = p[i-1];
			if(s[i] == 'L') p[i].first--;
			if(s[i] == 'R') p[i].first++;
			if(s[i] == 'U') p[i].second++;
			if(s[i] == 'D') p[i].second--;
		}
		vec.clear();
		for(int i = 0; i <= n; i++) vec.push_back(make_pair(p[i], i));
		sort(vec.begin(), vec.end());
		
		llint ans = inf, l, r;
		for(int i = 1; i < vec.size(); i++){
			if(vec[i].first == vec[i-1].first){
				if(ans > vec[i].second - vec[i-1].second){
					ans = vec[i].second - vec[i-1].second;
					l = vec[i-1].second;
					r = vec[i].second;
				}
			}
		}
		if(ans > inf/2) cout << -1 << "\n";
		else cout << l+1 << " " << r << "\n";
	}
	flush(cout);
	
	return 0;
}