#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	int b[m];
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			vector<int> freq(m, 0);
			for(int r = i; r <= j; r++){
				freq[a[r]]++;
			}
			int ok = 1;
			for(int q = 0; q < m; q++){
				if(freq[q] != b[q]){
					ok = 0;
				}
			}
			if(ok){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}