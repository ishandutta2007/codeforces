#include <bits/stdc++.h>
using namespace std;

const int R = 5.1e5;
using B = bitset<R>;
void solve(){
	vector<int> a[2];
	for(int j = 0; j < 2; j++){
		int r;
		cin >> r;
		a[j].resize(r);
		for(int& x : a[j]) cin >> x;
		sort(a[j].begin(), a[j].end());
	}
	if(a[0].size() != a[1].size()){
		cout << "No" << '\n';
		return;
	}
	vector<int> dir_len[2][2];
	for(int j = 0; j < 2; j++){
		int tot = 0;
		vector<B> f(a[j].size() + 1);
		f[0][0] = 1;
		for(int r = 0; r < (int)a[j].size(); r++){
			tot += a[j][r];
			f[r+1] = f[r] | (f[r] << a[j][r]);
		}
		if(tot % 2 != 0){
			cout << "No" << '\n';
			return;
		}
		if(f.back()[tot/2]){
			int cur = tot/2;
			for(int r = (int)a[j].size() - 1; r >= 0; r--){
				if(f[r][cur]){
					dir_len[j][0].push_back(a[j][r]);
				} else {
					cur -= a[j][r];
					dir_len[j][1].push_back(a[j][r]);					
				}
			}
		} else {
			cout << "No" << '\n';
			return;			
		}
	}
	vector<int> r = dir_len[0][0];
	vector<int> l = dir_len[0][1];
	vector<int> u = dir_len[1][0];
	vector<int> d = dir_len[1][1];
	sort(u.begin(), u.end());
	sort(d.rbegin(), d.rend());
	int lind = 0, rind = 0;
	int llen = 0;
	int rlen = 0;
	while(lind + rind + 1 < (int)d.size()){
		assert(lind < (int)l.size() && rind < (int)r.size());
		if(llen + l[lind] > rlen + r[rind]){
			rlen += r[rind];
			rind++;			
		} else {
			llen += l[lind];
			lind++;
		}
	}
	vector<int> dx;
	for(int i = lind - 1; i >= 0; i--) dx.push_back(-l[i]);
	for(int x : r) dx.push_back(x);
	for(int i = (int)l.size()-1; i >= lind; i--) dx.push_back(-l[i]);
	vector<int> dy;
	for(int x : d) dy.push_back(-x);
	for(int x : u) dy.push_back(x);
	cout << "Yes" << '\n';
	assert(dx.size() == dy.size());
	int cx = 0;
	int cy = 0;
	for(int i = 0; i < (int)dx.size(); i++){
		cout << cx << ' ' << cy << '\n';
		cy += dy[i];
		cout << cx << ' ' << cy << '\n';
		cx += dx[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}