#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int N, M, K;
	cin >> N >> M >> K;
	int C = N%M, pt = 1;
	for (int iter=1;iter<=K;iter++){
		vector<bool> vis(N+1); int npt = 1;
		for (int i=1;i<=M;i++){
			int cnt = i <= C ? N/M+1 : N/M;
			cout << cnt;
			if (i <= C){
				for (int j=0;j<cnt;j++){
					cout << ' ' << pt;
					vis[pt] = 1;
					pt = pt%N + 1;
				}
			}else{
				for (int j=0;j<cnt;j++){
					while (vis[npt]) npt++;
					cout << ' ' << npt++;
				}
			}
			cout << '\n';
		}
	}
	cout << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	for (cin >> T;T--;) solve();
}