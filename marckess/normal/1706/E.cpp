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

const int MX = 100005;
int n, m, q, p[MX], w[MX];
set<int> st[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

bool join (int a, int b, int ind) {
	a = parent(a), b = parent(b);
	if (a == b) return 0;
	
	if (st[a].size() < st[b].size())
		swap(a, b);
		
	for (int x : st[b]) {
		auto it = st[a].insert(x).fi;
		
		if (it != st[a].begin()) {
			auto jt = it;
			jt--;
			if (*jt + 1 == *it)
				w[*jt] = min(w[*jt], ind);
		}
		
		if (it != st[a].end()) {
			auto jt = it;
			jt++;
			if (*it + 1 == *jt)
				w[*it] = min(w[*it], ind);
		}
	}
	
	p[b] = a;
	st[b].clear();
	
	return 1;
}

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
				ST[j][i] = max(ST[j - 1][i], ST[j - 1][i + (1 << (j - 1))]); //put the function accordingly
	}

	T query (int l, int r){ 
		if (l > r) return 0;
		int j = logs[r - l + 1];
		return max(ST[j][l], ST[j][r - (1 << j) + 1]);
	}
};

SparseTable<int> *mx;

void main_() {
	cin >> n >> m >> q;
 	
	forr (i, 1, n) {
		p[i] = i;
		w[i] = 1e9;
		st[i].clear();
		st[i].insert(i);
	}
	
	forr (i, 1, m) {
		int u, v;
		cin >> u >> v;
		join(u, v, i);
	}
	
	vi a(n + 1);
	forr (i, 1, n)
		a[i] = w[i];
	mx = new SparseTable<int>(a);
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << mx->query(l, r - 1) << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}