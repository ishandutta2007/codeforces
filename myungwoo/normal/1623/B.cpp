#include <bits/stdc++.h>
using namespace std;

struct DS{
	DS(int n): n(n), nxt(n+1) {
		for (int i=1;i<=n;i++) nxt[i] = i;
	}
	int go(int n){
		return nxt[n] == n ? n : (nxt[n] = go(nxt[n]));
	}
	void rem(int n){
		nxt[n] = n+1;
	}
	int n;
	vector<int> nxt;
};

void solve()
{
	int N;
	cin >> N;
	struct Z{
		int a, b;
	} A[N+1];
	for (int i=1;i<=N;i++) cin >> A[i].a >> A[i].b;
	sort(A+1, A+N+1, [](const Z &a, const Z &b){
		return a.b-a.a < b.b-b.a;
	});
	DS ds(N);
	vector<tuple<int, int, int>> ans;
	for (int i=1;i<=N;i++){
		int t = ds.go(A[i].a);
		ans.emplace_back(A[i].a, A[i].b, t);
		ds.rem(t);
	}
	for (auto [a, b, c]: ans) cout << a << " " << b << " " << c << "\n";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}