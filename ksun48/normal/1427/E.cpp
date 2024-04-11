#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<pair<ll, ll>, char> > ops;

void op(ll a, char c, ll b){
	ops.push_back({{a, b}, c});
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll x;
	cin >> x;
	for(ll j = 0; j < 30; j++){
		op(x << j, '+', x << j);
	}
	ll cx = x;
	for(ll j = 1; j < 25; j++){
		if(cx & (1ll << j)){
			op(cx, '^', x << j);
			cx ^= (x << j);
		}
	}
	assert((x & cx) == 1);
	// x is big
	op(x, '+', cx);
	op(x+cx, '^', cx);
	ll y = (x + cx) ^ cx;
	assert(y == x + 2);

	op(y, '+', cx);
	op(y+cx, '^', cx);
	ll z = (y + cx) ^ cx;
	assert(z == y + 2);
	op(x, '^', y);
	op(y, '^', z);
	assert((x ^ y) == 2 || (y ^ z) == 2);
	for(ll j = 1; j < 30; j++){
		op(1ll << j, '+', 1ll << j);
	}
	for(ll j = 1; j < 30; j++){
		if(x & (1ll << j)){
			op(x, '^', 1ll << j);
			x ^= (1ll << j);
		}
	}
	assert(x == 1);
	cout << ops.size() << '\n';
	for(auto e : ops){
		cout << e.first.first << " " << (char)(e.second) << " " << e.first.second << '\n';
	}
}