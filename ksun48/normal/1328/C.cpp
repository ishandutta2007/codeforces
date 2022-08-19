#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t1, t2;
	bool eq = true;
	for(int i = 0; i < n; i++){
		int v = s[i] - '0';
		if(v == 0){
			t1 += '0';
			t2 += '0';
			continue;
		}
		if(!eq){
			t1 += '0';
			t2 += s[i];
			continue;
		}
		if(eq){
			t1 += '1';
			if(v == 2){
				t2 += '1';
			} else {
				t2 += '0';
				eq = false;
			}
		}
	}
	cout << t1 << '\n';
	cout << t2 << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}