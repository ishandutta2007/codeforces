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
typedef pair<P, llint> T;

llint n;
vector<T> ans;

llint Shift(llint x, llint s)
{
	for(int i = 0; i < s; i++){
		ans.push_back(T(P(x, x), 1));
		x <<= 1;
	}
	return x;
}
llint Add(llint a, llint b)
{
	ans.push_back(T(P(a, b), 1));
	return a+b;
}
llint Xor(llint a, llint b)
{
	ans.push_back(T(P(a, b), 0));
	return a^b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	while(n != 1){
		llint keta = 0;
		for(llint t = n; t; t>>=1) keta++;
		
		llint a = n, b = Shift(n, keta-1);
		if(n & 2){
			llint c = Add(a, b);
			b = Xor(a, c);
		}
		
		llint s = Add(a, b), x = Xor(a, b), d = Xor(s, x);
		for(int i = keta; i < 50; i++){
			if(b & (1LL<<i)) b = Xor(b, d);
			d = Shift(d, 1);
		}
		n = Xor(a, b);
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first.first << " ";
		if(ans[i].second == 0) cout << "^" << " ";
		else cout << "+" << " ";
		cout << ans[i].first.second << endl;
	}
	
	return 0;
}