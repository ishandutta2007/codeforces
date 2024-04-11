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

typedef int ll;
typedef int llint;
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

inline ll get(char c)
{
	if(c == 'A') return 0;
	if(c == 'T') return 1;
	if(c == 'G') return 2;
	if(c == 'C') return 3;
}

ll n;
string s;
ll Q;
BIT bit[11][10][4];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = s.size();
	s = "#" + s;

	rep(i, 1, 10){
		rep(j, 0, i-1){
			rep(k, 0, 3) bit[i][j][k] = BIT(100005);
		}
	}
	rep(i, 1, n){
		rep(j, 1, 10){
			bit[j][i%j][get(s[i])].add(i, 1);
		}
	}

	cin >> Q;
	ll type, l, r, x; string t; char c;
	rep(q, 1, Q){
		cin >> type;
		if(type == 1){
			cin >> x >> c;
			rep(j, 1, 10) bit[j][x%j][get(s[x])].add(x, -1);
			s[x] = c;
			rep(j, 1, 10) bit[j][x%j][get(s[x])].add(x, 1);
		}
		else{
			cin >> l >> r >> t;
			ll d = t.size(), ans = 0;
			rep(i, 0, d-1){
				ans += bit[d][(l+i)%d][get(t[i])].query(r) - bit[d][(l+i)%d][get(t[i])].query(l-1);
			}
			cout << ans << "\n";
		}
	}
	flush(cout);

	return 0;
}