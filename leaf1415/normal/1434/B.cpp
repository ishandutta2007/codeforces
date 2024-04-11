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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n;
list<llint> ls;
list<llint>::iterator p[100005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	string s; llint x;
	for(int i = 1; i <= 2*n; i++){
		cin >> s;
		if(s == "+") ls.push_back(-i);
		else{
			cin >> x;
			ls.push_back(x);
		}
	}
	for(auto it = ls.begin(); it != ls.end(); it++) if(*it > 0) p[*it] = it;
	
	for(int i = 1; i <= n; i++){
		auto it = p[i];
		if(it == ls.begin()){
			cout << "NO" << endl;
			return 0;
		}
		it--;
		if(*it > 0){
			cout << "NO" << endl;
			return 0;
		}
		mp[-*it] = i;
		ls.erase(it);
		ls.erase(p[i]);
	}
	
	cout << "YES" << endl;
	for(auto x : mp) cout << x.second << " ";  cout << endl;
	
	return 0;
}