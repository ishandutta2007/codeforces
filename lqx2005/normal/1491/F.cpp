#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef pair<int, int> par;
typedef long long LL;
typedef double db;
set<int> L, R, A;
int n;

void put(set<int> &s) {
	for(auto x : s) cout << x <<" ";
	cout << endl;	
}

int ask(set<int> &l, set<int> &r) {
	cout << "? " << l.size() <<" " << r.size() << endl;
	put(l), put(r);
	int x;
	cin >> x;
	assert(!l.empty() && !r.empty());
	return x;
}



void work() {
	L.clear(), R.clear(), A.clear();
	cin >> n;
	rep(i, 1, n) L.insert(i);
	int mx = 0, s = -1;
	rep(i, 1, n) {
		L.erase(i), R.insert(i);
		int x = ask(L, R);
		if(x != 0) {
			mx = i;
			s = x;
			break;
		}
		R.erase(i);
	}
	L.clear(), R.clear();
	L.insert(mx);
	
	rep(i, mx + 1, n - 1) {
		R.clear();
		R.insert(i);
		int x = ask(L, R);
		s -= x;
		if(x == 0) A.insert(i);
	}
	if(s == 0) A.insert(n);
	int l = 1, r = mx - 1, b = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		R.clear();
		rep(i, 1, mid) R.insert(i);
		int x = ask(L, R);
		if(x != 0) r = mid - 1;
		else b = mid, l = mid + 1;
	}
	rep(i, 1, mx - 1) if(i != b + 1) A.insert(i);
	cout << "! " << A.size() <<" ";
	for(auto x : A) cout << x << " ";
	cout << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(; T--; ) work();	
	return 0;
}