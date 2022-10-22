#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
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
const int N = 2e5 + 10;
int n;
int a[N];
int main() {
	cin >> n;
	int k = 1, res = 0;
	for(int i = 1; i < n; i++) {
		int m = (n + i) / (i + 1);
		if(res < n - m - i) res = n - m - i, k = i;
	}
	k++;
	while(1) {
		vector<int> id;
		for(int i = 1; i <= n; i += k) {
			for(int j = i; j < i + k - 1 && j < n; j++) {
				if(!a[j]) id.push_back(j);
			}
		}
		if(k - 1 >= SZ(id)) break;
		cout << SZ(id) << " ";
		for(int i = 0; i < SZ(id); i++) cout << id[i] <<" ", a[id[i]] = 1;
		cout << endl;
		int x;
		cin >> x;
		assert(x > 0);
		for(int i = 0; i < SZ(id); i++) a[(x + i - 1) % n + 1] = 0;
	}
	cout << 0 << endl;
	return 0;
}