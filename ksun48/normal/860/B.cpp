#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	string a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> d[n];
	for(int i = 0; i < n; i++){
		for(int x = 0; x < 9; x++){
			for(int y = x ; y < 9; y++){
				int f = 1;
				for(int j = x; j <= y; j++){
					f *= 10;
					f += a[i][j] - '0';
				}
				d[i].push_back(f);
			}
		}
	}
	map<int, int> freq;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < d[i].size(); j++){
			freq[d[i][j]]++;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < d[i].size(); j++){
			freq[d[i][j]]--;
		}
		int ans = 2000000000;
		for(int j = 0; j < d[i].size(); j++){
			if(freq[d[i][j]] == 0){
				if(d[i][j] < ans){
					ans = d[i][j];
				}
			}
		}
		for(int j = 0; j < d[i].size(); j++){
			freq[d[i][j]]++;
		}
		int f = ans;
		vector<int> b;
		while(f > 1){
			b.push_back(f % 10);
			f /= 10;
		}
		for(int j = b.size() - 1; j >= 0; j--){
			cout << b[j];
		}
		cout << endl;
	}

}