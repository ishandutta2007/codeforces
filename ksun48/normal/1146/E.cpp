#include <bits/stdc++.h>
using namespace std;

vector<int> what(110000, 0);
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int gflip = 0;

	map<int,int> ops;

	for(int i = 0; i < q; i++){
		string c;
		cin >> c;

		char p = c[0];
		int x;
		cin >> x;
		if(gflip){
			x = -x;
			p = p ^ '<' ^ '>';
		}
		if(p == '<'){
			x--;
		} else if(p == '>'){
			x++;
		}
		int newgflip = 0;
		if(p == '>' && x < 0){
			newgflip ^= 1;
			p = '<';
			x -= 1;
		}
		if(p == '<' && x > 0){
			newgflip ^= 1;
			p = '>';
			x += 1;
		}
		if(p == '>' && x < 0) assert(false);
		if(p == '<' && x > 0) assert(false);

		int y = abs(x);
		while(!ops.empty() && ops.rbegin()->first >= y){
			ops.erase(prev(ops.end()));
		}
		if(p == '>'){
			ops[y] = -1;
		} else {
			ops[y] = 1;
		}
		gflip = newgflip ^ gflip;
	}
	for(int i = 0; i < what.size(); i++){
		if(ops.count(i)){
			what[i] = ops[i];
		} else if(i > 0){
			what[i] = what[i-1];
		}
	}
	for(int i = 0; i < n; i++){
		int x = a[i];
		if(what[abs(x)] == 0){
		} else if(what[abs(x)] == 1){
			x = abs(x);
		} else if(what[abs(x)] == -1){
			x = -abs(x);
		}
		if(gflip){
			x = -x;
		}
		cout << x << ' ';
	}
	cout << '\n';
}