#include<bits/stdc++.h>

using namespace std;

#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
int n;

void ask(int b, par p) { cout << b <<" " << p.x <<" " << p.y << endl; }

int main() {
	cin >> n;
	vector<par> e, o;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if((i + j) & 1) o.push_back(mp(i, j));
			else e.push_back(mp(i, j)); 
		}
	}
	int a;
	for(;;) {
		if(e.empty() && o.empty()) break;
		cin >> a;
		if(a == 1) {
			if(!o.empty()) ask(2, o.back()), o.pop_back();
			else {
				ask(3, e.back()), e.pop_back();
			}
		} else {
			if(!e.empty()) {
				ask(1, e.back()), e.pop_back();
			} else {
				ask(a ^ 1, o.back()), o.pop_back();
			}
		}
	}
	return 0;
}