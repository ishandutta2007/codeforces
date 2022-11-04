#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

template<typename T>
struct SparseTable{
	vector<vector<T>> ST;
	vector<int> logs;
	int K, N;
 
	SparseTable(vector<T> & arr){
		N = arr.size();
		K = log2(N) + 2;
		ST.assign(K + 1, vector<T>(N));
		logs.assign(N + 1, 0);
		
		for(int i = 2; i <= N; ++i)
			logs[i] = logs[i >> 1] + 1;
		
		for(int i = 0; i < N; ++i)
			ST[0][i] = arr[i];
			
		for(int j = 1; j <= K; ++j)
			for(int i = 0; i + (1 << j) <= N; ++i)
				ST[j][i] = max(ST[j - 1][i], ST[j - 1][i + (1 << (j - 1))]);
	}
 
	T query (int l, int r){
		if (l > r) return 0;
		int j = logs[r - l + 1];
		return max(ST[j][l], ST[j][r - (1 << j) + 1]);
	}
};

const int MX = 200005;
int n, m, q, a[MX];
SparseTable<int> *st;

void main_() {
	cin >> n >> m;
	vi v(m + 1);
	forr (i, 1, m) {
		cin >> a[i];
		v[i] = a[i];
	}
	
	st = new SparseTable<int>(v);
	
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		
		if (y1 > y2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		
		if ((x2 - x1) % k) {
			cout << "NO" << endl;
			continue;
		}
		
		if ((y2 - y1) % k) {
			cout << "NO" << endl;
			continue;
		}
		
		int t = x1 + k * ((n - x1) / k);
		if (st->query(y1, y2) >= t) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}