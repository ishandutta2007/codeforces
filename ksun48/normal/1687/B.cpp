#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	auto query = [&](string s) -> int {
		cout << "? " << s << '\n';
		cout << flush;
		int res;
		cin >> res;
		return res;
	};
	vector<int> len(m);
	for(int i = 0; i < m; i++){
		string s(m, '0');
		s[i] = '1';
		len[i] = query(s);
	}
	vector<int> ord(m);
	for(int i = 0; i < m; i++) ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int x, int y){
		return len[x] < len[y];
	});
	int cur = 0;
	string on(m, '0');
	for(int x : ord){
		string non = on;
		non[x] = '1';
		int z = query(non);
		if(z - cur == len[x]){
			on = non;
			cur = z;
		}
	}
	cout << "! " << cur << '\n';
}