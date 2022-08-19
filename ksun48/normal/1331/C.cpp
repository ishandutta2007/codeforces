#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> idx = {0, 5, 3, 2, 4, 1};
	int ans = 0;
	for(int i = 0; i < 6; i++){
		ans ^= (1 & (n >> (5 - idx[i]))) << (5 - i);
	}
	cout << ans << '\n';
}