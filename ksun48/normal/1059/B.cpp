#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
	}
	vector<string> t = s;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			t[i][j] = '.';
		}
	}
	for(int i = 0; i + 2 < n; i++){
		for(int j = 0; j + 2 < m; j++){
			int bad = 0;
			for(int a = 0; a <= 2; a++){
				for(int b = 0; b <= 2; b++){
					if(a == 1 && b == 1) continue;
					if(s[i+a][j+b] == '.'){
						bad = 1;
					}
				}
			}
			if(!bad){
				for(int a = 0; a <= 2; a++){
					for(int b = 0; b <= 2; b++){
						if(a == 1 && b == 1) continue;
						t[i+a][j+b] = '#';
					}
				}
			}
		}
	}
	if(s == t){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}