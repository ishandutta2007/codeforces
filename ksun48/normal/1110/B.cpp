#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	vector<int> save;
	for(int i = 0; i + 1 < n; i++){
		save.push_back(b[i+1] - b[i] - 1);
	}
	sort(save.begin(), save.end());
	reverse(save.begin(), save.end());
	int ans = b[n-1] - b[0] + 1;
	for(int i = 0; i < k-1 && i < save.size(); i++){
		ans -= save[i];
	}
	cout << ans << '\n';
}