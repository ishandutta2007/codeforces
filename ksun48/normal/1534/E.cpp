#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	if(k % 2 == 0 && n % 2 == 1){
		cout << -1 << '\n';
		exit(0);
	}
	int r = k;
	while(r < n || ((r - n) % 2 != 0) || (1 + 2 * (((r - n) / 2 + n-1) / n)) > (r / k)) r += k;
	int extra = (r - n) / 2;
	vector<int> need(n, 1);
	for(int i = 0; i < extra; i++){
		need[i % n] += 2;
	}
	int rounds = r / k;
	int z = 0;
	for(int i = 0; i < rounds; i++){
		vector<int> idx(n);
		for(int j = 0; j < n; j++) idx[j] = j;
		sort(idx.begin(), idx.end(), [&](int x, int y) { return need[x] < need[y]; } );
		reverse(idx.begin(), idx.end());
		cout << '?';
		for(int j = 0; j < k; j++){
			cout << ' ' << (idx[j] + 1);
			need[idx[j]]--;
		}
		cout << '\n';
		cout << flush;
		int res;
		cin >> res;
		z ^= res;
	}
	cout << "! " << z << '\n';
}