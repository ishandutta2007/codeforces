#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> P;
typedef long long LL;
typedef double db;
const LL inf = 1e14;
int t;
LL X;
int ask(LL x) {
	if(x > inf) return 0;
	cout << "? " << x << endl;
	string req;
	cin >> req;
	if(req == "Lucky!") return X += x, 1;
	assert(x <= X);
	if(req == "Fraudster!") return X -= x, 0;
	assert(0);
}

void work() {
	LL L = 1, R = inf;
	X = 1;
	if(!ask(1)) return cout << "! 0" << endl, void();
	L = 1;
	while(1) {
		LL mid = X;
		if(ask(mid)) L = mid;
		else {
			R = mid - 1;
			break;
		}
	}
	ask(L);
	LL best = L;
	L++;
	while(L <= R) {
		while(X < L) ask(best);
		LL mid = L + ((long double)0.5 * (R - L) *  X / (R + X));
		mid = min(mid, X);
//		cout << L <<" " << R << " " << cnt <<" " << mid <<" " << best << endl;
		if(ask(mid)) best = mid, L = mid + 1;
		else R = mid - 1;
	}
	cout << "! " << best << endl;
	return;
}

int main() {
	cin >> t;
	for(; t--; ) work();
	return 0;
}