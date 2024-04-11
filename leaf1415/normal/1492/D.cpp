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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll a, b, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> k;
	
	if(k == 0){
		cout << "Yes" << endl;
		rep(i, 1, b) cout << 1;
		rep(i, 1, a) cout << 0;
		cout << endl;
		rep(i, 1, b) cout << 1;
		rep(i, 1, a) cout << 0;
		cout << endl;
		return 0;
	}
	
	if(a == 0 || b == 1 || k > a+b-2){
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	
	string s;
	s += '1';
	rep(i, 1, a) s += '0';
	rep(i, 1, b-1) s += '1';
	
	string t = s;
	
	ll p;
	rep(i, 1, (int)s.size()-1){
		if(s[i] == '1'){
			p = i;
			break;
		}
	}
	ll x = min(a, k);
	s[p] = '0';
	s[p-x] = '1';
	k -= x;
	
	rep(i, p+1, (int)s.size()-1){
		if(k <= 0) break;
		s[i] = '0';
		s[i-1] = '1';
		k--;
	}
	
	cout << s << endl;
	cout << t << endl;
	
	return 0;
}