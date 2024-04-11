#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	bool is0 = false;
	bool is1 = false;
	bool is2 = false;
	bool is3 = false;
	bool is4 = false;
	is0 = true;

	bool f1 = true, f2 = true, f3 = true, f4 = true;
	for(int i = 0; i < n; i++){
		bool row_works = true;
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'P') row_works = false;
		}
		if(row_works) is2 = true;
	}
	for(int j = 0; j < m; j++){
		bool col_works = true;
		for(int i = 0; i < n; i++){
			if(s[i][j] == 'P') col_works = false;
		}
		if(col_works) is2 = true;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'P'){
				is0 = false;
				if(i == 0) f1 = false;
				if(i == n-1) f2 = false;
				if(j == 0) f3 = false;
				if(j == m-1) f4 = false;
			} else {
				if((i == 0 || i == n-1) && (j == 0 || j == m-1)){
					is2 = true;
				}
				if((i == 0 || i == n-1) || (j == 0 || j == m-1)){
					is3 = true;
				}
				is4 = true;
			}
		}
	}
	is1 = f1 | f2 | f3 | f4;
	if(is0){
		cout << 0 << '\n';
	} else if(is1){
		cout << 1 << '\n';
	} else if(is2){
		cout << 2 << '\n';
	} else if(is3){
		cout << 3 << '\n';
	} else if(is4){
		cout << 4 << '\n';
	} else {
		cout << "MORTAL" << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}