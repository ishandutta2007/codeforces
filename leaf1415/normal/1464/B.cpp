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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

string s;
vector<ll> vec;
ll x, y;
ll sum[3][100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	cin >> x >> y;
	if(x > y){
		swap(x, y);
		for(auto &c : s){
			if(c == '0') c = '1';
			else if(c == '1') c = '0';
		}
	}
	ll n = s.size();
	s = "#" + s;
	
	//cout << s << endl;
	
	rep(i, 1, n){
		rep(j, 0, 2) sum[j][i] = sum[j][i-1];
		if(s[i] != '?') sum[s[i]%2][i]++;
		else sum[2][i]++;
	}
	
	ll tmp = 0;
	rep(i, 1, n){
		if(s[i] == '1') tmp += (sum[0][i-1]+sum[2][i-1])*x;
		else tmp += sum[1][i-1]*y;
	}
	rep(i, 1, n) if(s[i] == '?') vec.push_back(i);
	reverse(all(vec));
	
	ll ans = tmp;
	//cout<< ans << endl;
	
	for(auto i : vec)
	{
		tmp -= (sum[2][n]-sum[2][i] + sum[1][n]-sum[1][i])*x;
		tmp -= sum[1][i-1]*y;
		tmp += (sum[0][n]-sum[0][i])*y;
		tmp += (sum[2][i-1]+sum[0][i-1])*x;
		chmin(ans, tmp);
		//cout << tmp << endl;
	}
	cout << ans << endl;
	
	return 0;
}