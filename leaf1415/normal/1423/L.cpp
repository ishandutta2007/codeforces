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
#define pback push_back
#define inf 1e18

using namespace std;

typedef long long llint;
typedef unsigned long long ulint;

const static llint L = 4;
struct Hash{
	vector<ulint> vec;
	Hash(){
		vec.resize(L);
	}
	bool operator<(const Hash &ope)const{
		return vec < ope.vec;
	}
};

typedef pair<Hash, llint> P;


llint n, m, Q;
vector<llint> vec[35];
Hash b[35];
Hash beki[1005];
vector<P> hvec;
map<Hash, llint> mp;

llint getrand(){
	llint ret = rand();
	ret = ret * RAND_MAX + rand();
	ret = ret * RAND_MAX + rand();
	return ret;
}

inline void add(Hash &a, Hash &b)
{
	for(int i = 0; i < L; i++) a.vec[i] ^= b.vec[i];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	srand(time(NULL));
	for(int i = 0; i < L; i++){
		ulint H = getrand() % 900000000 + 100000000;
		beki[0].vec[i] = 1;
		for(int j = 1; j < 1005; j++) beki[j].vec[i] = beki[j-1].vec[i] * H;
	}
	
	cin >> n >> m >> Q;
	llint x, y;
	for(int i = 0; i < m; i++){
		cin >> x;
		for(int j = 0; j < x; j++){
			cin >> y;
			vec[i].push_back(y);
		}
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < vec[i].size(); j++){
			add(b[i], beki[vec[i][j]]);
		}
	}
	
	llint M2 = 1<<(m-m/3);
	for(int i = 0; i < M2; i++){
		Hash h; llint cnt = 0;
		for(int j = 0; j < m-m/3; j++){
			if(i & (1<<j)) add(h, b[j+m/3]), cnt++;
		}
		if(mp.count(h) == 0) mp[h] = inf;
		chmin(mp[h], cnt);
	}
	
	llint M = 1<<(m/3);
	for(int i = 0; i < M; i++){
		Hash h; llint cnt = 0;
		for(int j = 0; j < m/3; j++){
			if(i & (1<<j)) add(h, b[j]), cnt++;
		}
		hvec.push_back(P(h, cnt));
	}
	
	for(int q = 0; q < Q; q++){
		cin >> x;
		Hash h;
		for(int j = 0; j < x; j++){
			cin >> y;
			add(h, beki[y]);
		}
		llint ans = inf; Hash H;
		for(auto p: hvec){
			H = h;
			add(H, p.first);
			if(mp.count(H)) ans = min(ans, p.second + mp[H]);
		}
		if(ans > inf/2) ans = -1;
		cout << ans << endl;
	}
	
	return 0;
}