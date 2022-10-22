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

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};


llint n;
string s, t;
vector<llint> svec[26], tvec[26];
llint p[200005];
BIT bit(200005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	
	t = s;
	reverse(t.begin(), t.end());
	
	for(int i = 0; i < n; i++){
		svec[s[i]-'a'].push_back(i);
		tvec[t[i]-'a'].push_back(i);
	}
	
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < svec[i].size(); j++){
			p[svec[i][j]+1] = tvec[i][j] + 1;
		}
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		ans += bit.query(n) - bit.query(p[i]);
		bit.add(p[i], 1);
	}
	cout << ans << endl;
	
	return 0;
}