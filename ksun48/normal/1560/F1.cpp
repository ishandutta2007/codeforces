#include <bits/stdc++.h>
using namespace std;

vector<set<int>> ans(3);

void init(){
	ans[1].insert(1111111111);
	ans[2].insert(1000000000);
	for(int b = 1; b <= 9; b++){
		for(int c = 0; c < (1 << (b-1)); c++){
			int d = 0, e = 0;
			int p10 = 1;
			for(int j = 0; j < b; j++){
				if(c & (1 << j)){
					d += p10;
				} else {
					e += p10;
				}
				p10 *= 10;
			}
			for(int r = 0; r <= 9; r++){
				for(int s = 0; s <= 9; s++){
					ans[2].insert(d * r + e * s);
					if(r == s) ans[1].insert(d * r + e * s);
				}
			}
		}
	}
}

void solve(){
	int n, k;
	cin >> n >> k;
	cout << (*ans[k].lower_bound(n)) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	while(T--) solve();
}