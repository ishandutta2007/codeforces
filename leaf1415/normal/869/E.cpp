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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<P, P> R;

llint getrand(){
	llint ret = rand();
	ret = ret * RAND_MAX + rand();
	ret = ret * RAND_MAX + rand();
	return ret;
}

struct BIT2D{
	int hsize, wsize;
	vector<vector<llint> > bit;
	BIT2D(){hsize = wsize = 0;}
	BIT2D(int h, int w){
		hsize = h, wsize = w;
		bit.resize(wsize+1);
		rep(i, 1, wsize) bit[i].resize(hsize+1);
		init();
	}
	void init(){
		for(int y = 1; y <= hsize; y++){
			for(int x = 1; x <= wsize; x++){
				bit[x][y] = 0;
			}
		}
	}
	llint query(int x, int y){
		llint ret = 0;
		for(int i = x; i > 0; i -= i&(-i)){
			for(int j = y; j > 0; j -= j&(-j)){
				ret ^= bit[i][j];
			}
		}
		return ret;
	}
	void add(int x, int y, llint val){
		if(x == 0 || y == 0) return;
		for(int i = x; i <= wsize; i += i&(-i)){
			for(int j = y; j <= hsize; j += j&(-j)){
				bit[i][j] ^= val;
			}
		}
	}
};

const ll L = 6;
ll H[L], beki[L][100005];
ll h, w, Q;
BIT2D bit[L];
map<R, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	
	for(int i = 0; i < L; i++){
		H[i] = getrand() % 900000000 + 100000000;
		bit[i] = BIT2D(2505, 2505);
	}
	
	rep(i, 0, L-1){
		beki[i][0] = 1;
		rep(q, 1, 100003) beki[i][q] = beki[i][q-1] * H[i] % mod;
	}
	
	cin >> h >> w >> Q;
	ll t, sx, sy, tx, ty;
	rep(q, 1, Q){
		//cout << q << endl;
		cin >> t >> sy >> sx >> ty >> tx;
		if(t == 1){
			rep(i, 0, L-1){
				bit[i].add(sx, sy, beki[i][q]);
				bit[i].add(sx, ty+1, beki[i][q]);
				bit[i].add(tx+1, sy, beki[i][q]);
				bit[i].add(tx+1, ty+1, beki[i][q]);
			}
			mp[R(P(sx, sy), P(tx, ty))] = q;
		}
		if(t == 2){
			ll qid = mp[R(P(sx, sy), P(tx, ty))];
			rep(i, 0, L-1){
				bit[i].add(sx, sy, beki[i][qid]);
				bit[i].add(sx, ty+1, beki[i][qid]);
				bit[i].add(tx+1, sy, beki[i][qid]);
				bit[i].add(tx+1, ty+1, beki[i][qid]);
			}
		}
		if(t == 3){
			bool flag = true;
			rep(i, 0, L-1) flag &= (bit[i].query(sx, sy) == bit[i].query(tx, ty));
			if(flag) cout << "Yes" << "\n";
			else cout << "No" << "\n";
		}
		
		/*rep(y, 1, h){
			rep(x, 1, w){
				cout << bit[0].query(x, y) << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
	flush(cout);
	
	return 0;
}