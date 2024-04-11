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
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<ll, string> Q;

string s;

ll calc(ll a, ll b)
{
	string t = s; ll ret = 0;
	int p = -1;
	for(int i = (int)t.size()-1; i >= 0; i--){
		if(t[i] == '0' + b){
			p = i;
			break;
		}
	}
	if(p == -1) return inf;
	ret += (int)t.size()-1 - p;
	t.erase(t.begin()+p);
	t += '0' + b;

	p = -1;
	for(int i = (int)t.size()-2; i >= 0; i--){
		if(t[i] == '0' + a){
			p = i;
			break;
		}
	}
	if(p == -1) return inf;
	ret += (int)t.size()-2 - p;
	t.erase(t.begin()+p);
	t.pop_back();
	t += '0' + a;
	t += '0' + b;

	if(t.front() != '0') return ret;

	p = -1;
	for(int i = 0; i < (int)t.size()-2; i++){
		if(t[i] != '0'){
			p = i;
			break;
		}
	}
	if(p == -1) return inf;
	ret += p;

	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	ll ans = inf;
	chmin(ans, calc(2, 5));
	chmin(ans, calc(7, 5));
	chmin(ans, calc(5, 0));
	chmin(ans, calc(0, 0));
	if(ans > inf/2) ans = -1;
	cout << ans << endl;

	return 0;
}