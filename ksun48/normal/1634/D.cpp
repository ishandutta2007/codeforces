#include <bits/stdc++.h>
using namespace std;

int ask(vector<int> c){
	cout << "? " << (c[0]+1) << ' ' << (c[1]+1) << ' ' << (c[2]+1) << '\n';
	cout << flush;
	int res;
	cin >> res;
	return res;
}

void solve(){
	int n;
	cin >> n;
	vector<int> cs = {0, 1, 2};
	int cp = ask(cs);
	for(int i = 3; i < n; i++){
		vector<int> v1 = {cs[0], cs[1], i};
		vector<int> v2 = {cs[0], cs[2], i};
		int p1 = ask(v1);
		int p2 = ask(v2);
		int maxp = max({cp, p1, p2});
		if(maxp == p1){
			cs = v1;
		} else if(maxp == p2){
			cs = v2;
		}
		cp = maxp;
	}
	int r = 0;
	for(int x = 0; x < 4; x++) for(int c : cs) if(r == c) r++;
	vector<int> v2 = {cs[0], cs[1], r};
	vector<int> v1 = {cs[0], cs[2], r};
	vector<int> v0 = {cs[1], cs[2], r};
	int p0 = ask(v0);
	int p1 = ask(v1);
	int p2 = ask(v2);
	int maxp = max({p0, p1, p2});
	if(maxp == p0){
		cout << "! " << (cs[1] + 1) << ' ' << (cs[2] + 1) << '\n';
	} else if(maxp == p1){	
		cout << "! " << (cs[0] + 1) << ' ' << (cs[2] + 1) << '\n';
	} else if(maxp == p2){
		cout << "! " << (cs[0] + 1) << ' ' << (cs[1] + 1) << '\n';
	}
	cout << flush;
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}