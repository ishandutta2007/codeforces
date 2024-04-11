#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> deg(n, 0);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		deg[u]++;
		deg[v]++;
	}
	int nl = 0;
	for(int i = 0; i < n; i++){
		if(deg[i] == 1) nl++;
	}
	double ans = double(2.0 * s) / double(nl);
	cout << fixed << setprecision(10);
	cout << ans << endl;
}