#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int N, K;
	cin >> N >> K;
	if (K > (N+1)/2){ cout << "-1\n"; return; }
	for (int i=1;i<=N;i++){
		for (int j=1;j<=N;j++){
			if (i == j && i%2 == 1 && (i+1)/2 <= K) cout << 'R';
			else cout << '.';
		}
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}