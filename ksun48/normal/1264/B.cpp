#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<int> x(3);
	for(int i = 0; i < 4; i++) cin >> x[i];

	vector<int> c = {x[0] + x[2], x[1] + x[3]};

	int n = c[0] + c[1];
	for(int p = 0; p < 2; p++){
		int diff = c[1^p] - c[p];
		if(diff != 0 && diff != -1) continue;
		int r = x[3 * p];
		int s = x[3 * (1^p)];
		vector<bool> used(n, false);
		bool works = true;
		int next_use = 1;
		for(int i = 0; i < r; i++){
			if(2 * i >= n){
				works = false;
				break;
			}
			used[2 * i] = true;
			next_use = 2 * i + 3;
		}
		if(!works) continue;
		for(int i = 0; i < s; i++){
			int j = next_use + 2 * i;
			if(j >= n){
				works = false;
				break;
			}
			used[j] = true;
		}
		if(!works) continue;
		cout << "YES" << '\n';
		for(int i = 0; i < n; i++){
			int which = (1 ^ p ^ i) & 1;
			cout << ((which + 1) ^ (2 * (int)used[i])) << ' ';
		}
		cout << '\n';
		return 0;
	}
	cout << "NO" << '\n';
}