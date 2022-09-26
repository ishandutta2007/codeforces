#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505;

int r,c;
char s[N][N];
signed main() {
	cin >> r >> c;
	for(int i = 0;i < r;++i) {
		for(int j = 0;j < c;++j) {
			cin >> s[i][j];
		}
	}
	bool ok = true;
	for(int i = 0;i < r;++i) {
		for(int j = 0;j < c;++j) {
			if(s[i][j] != 'S') continue;
			if(s[i + 1][j] == 'W' || s[i][j + 1] == 'W') ok = false;
			if(i && s[i - 1][j] == 'W') ok = false;
			if(j && s[i][j - 1] == 'W') ok = false;
		}
	}
	
	if(!ok) return cout << "No" << endl,0;
	cout <<"Yes" << endl;
	for(int i = 0;i < r;++i) {
		for(int j = 0;j < c;++j) {
			if(s[i][j] == '.') cout <<"D";
			else cout<<s[i][j];
		}
		cout <<'\n';
	}
}