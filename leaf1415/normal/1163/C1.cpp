#include <iostream>
#include <utility>
#include <cstdlib>
#include <set>
#include <map>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, P> L;

llint n;
llint x[1005], y[1005];
set<L> S;
map<P, llint> mp;

llint gcd(llint a, llint b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i >= j) continue;
			int s = i, t = j;
			L l;
			if(x[s] == x[t]){
				l = make_pair(make_pair(1, 0), make_pair(x[s], 1));
			}
			else{
				if(x[s] > x[t]) swap(s, t);
				llint dx = x[t] - x[s], dy = y[t] - y[s];
				llint d = gcd(abs(dx), abs(dy));
				dx /= d, dy /= d;
				l.first = make_pair(dy, dx);
				
				llint bunsi = (dx*y[s] - dy*x[s]), bunbo = dx;
				d = gcd(abs(bunsi), abs(bunbo));
				bunsi /= d, bunbo /= d;
				l.second = make_pair(bunsi, bunbo);
			}
			S.insert(l);
		}
	}
	llint lnum = S.size();
	
	for(auto it = S.begin(); it != S.end(); it++) mp[it->first]++;
	llint ans = 0;
	for(auto it = mp.begin(); it != mp.end(); it++){
		ans += it->second * (it->second-1) / 2;
	}
	cout << lnum*(lnum-1)/2 - ans << endl;
	
	return 0;
}