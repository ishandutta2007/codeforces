#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
queue<pair<int, int>> q[2];

void solve(){
	cin >> n;

	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) q[(i + j) % 2].push({i, j});

	int c; cin >> c;

	int A = 1, B = 1;
	while(A == c) A++;
	while(B == c || B == A) B++;

	auto [x, y] = q[0].front(); q[0].pop();
	cout << A << " " << x << " " << y << "\n";
	cout.flush();

	for(int T=2;T<=n*n;T++){
		int c; cin >> c;

		if(q[0].empty()){
			auto [x, y] = q[1].front(); q[1].pop();

			int b = 1;
			while(b == A || b == c) b++;

			cout << b << " " << x << " " << y << "\n";
		}else if(q[1].empty()){
			auto [x, y] = q[0].front(); q[0].pop();

			int b = 1;
			while(b == B || b == c) b++;

			cout << b << " " << x << " " << y << "\n";
		}else if(c != A){
			auto [x, y] = q[0].front(); q[0].pop();
			cout << A << " " << x << " " << y << "\n";
		}else{
			auto [x, y] = q[1].front(); q[1].pop();
			cout << B << " " << x << " " << y << "\n";
		}

		cout.flush();
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int tc = 1;// cin >> tc;
	while(tc--) solve();
}