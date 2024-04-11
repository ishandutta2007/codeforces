#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	if(n <= 3){
		cout << 0 << '\n';
		return 0;
	}
	int abest = 0;
	int zbest = 0;
	for(int a = 1; a < n; a++){
		int z = n - (n + a) / (a + 1) - a;
		if(z > zbest){
			abest = a;
			zbest = z;
		}
	}
	vector<int> st(n, 0);
	while(true){
		vector<int> ask;
		for(int i = 0; i < n; i++){
			if(i % (abest + 1) == 0) continue;
			if(st[i]) continue;
			ask.push_back(i);
			st[i] = 1;
		}
		cout << ask.size();
		for(int a : ask) cout << ' ' << a + 1;
		cout << '\n';
		cout << flush;
		if(ask.empty()) break;
		int v;
		cin >> v;
		v--;
		for(int i = 0; i < (int)ask.size(); i++) st[(i + v) % n] = 0;
		int cnt = 0;
		for(int r : st) cnt += r;
		if(cnt == zbest){
			cout << 0 << '\n';
			break;
		}
	}
}