#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	cin >> a >> b;
	vector<vector<int> > s(a, vector<int>(b, 0));
	for(int j = 0; j < 2; j++){
		for(int x = 0; x < a; x++){
			for(int y = 0; y < b; y++){
				int q;
				cin >> q;
				s[x][y] ^= q;
			}
		}
	}
	for(int x = 0; x < a; x++){
		for(int y = 0; y < b; y++){
			if(s[x][y]){
				s[x][y] ^= 1;
				s[x][0] ^= 1;
				s[0][y] ^= 1;
				s[0][0] ^= 1;
			}
		}
	}
	for(int x = 0; x < a; x++){
		for(int y = 0; y < b; y++){
			if(s[x][y]){
				cout << "No" << '\n';
				exit(0);
			}
		}
	}
	cout << "Yes" << '\n';
}