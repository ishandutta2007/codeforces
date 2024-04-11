#include<bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
using namespace std;
typedef __int128 lll;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 100 + 10, M = 20 + 10, K = 15000 + 10;
mt19937 gen(__builtin_ia32_rdtsc());
int n, m, nm, beg[N];
int shift[N], ans[N], stk[K], top = 0, tot = 0;
int rd(int l, int r) {
	uniform_int_distribution<int> rng(l, r);
	return rng(gen);
}
int check(int l, int r, int x) {
	if(l < r) return l <= x && x < r;
	return x >= l || x < r;
}
int ask(int x, int d) {
	shift[x] += d;
    tot++;
    assert(tot <= 15000);
	cout << "? " << x <<" " << d << endl;
    int cnt;
    cin >> cnt;
	stk[++top] = cnt;
	return cnt;
}
int main() {
	cin >> n >> m;
	nm = n * m;
	ask(0, 1);
	vector<int> id;
	for(int i = 1; i < n; i++) id.push_back(i);
	for(int i = 1; i < n; i++) {
		shuffle(id.begin(), id.end(), gen);
		while(1) {
			ask(0, 1);
			if(stk[top] > stk[top - 1]) break;
		};
		while(1) {
			ask(0, 1);
			if(stk[top] <= stk[top - 1]) break;
		}
		ask(0, -1);
		// for(int j = 0; j < n; j++) cout << (shift[j] + beg[j] + nm) % nm << " ";
		// cout << endl;
		int key = -1;
        int d = -1;
		for(int x : id) {
			ask(x, -1);
			ask(0, d);
			if(stk[top] * d <= stk[top - 1] * d) {
				ans[x] = ((-(d == 1) - shift[x] + shift[0]) % nm + nm) % nm;
				key = x;
				break;
			} else d = -d;
		}
		id.erase(find(id.begin(), id.end(), key));
		for(int j = 1; j <= m; j++) ask(key, -1);
		if(d == 1) ask(0, -1);
	}	
	cout << "! ";
	for(int i = 1; i < n; i++) cout << ((ans[i] - shift[0] + shift[i]) % nm + nm) % nm << " ";
	cout << endl;
	return 0;
}