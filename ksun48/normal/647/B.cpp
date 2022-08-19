#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	string a[n];
	int mini = 100000;
	int minj = 100000;
	int maxi = 0;
	int maxj = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '*'){
				mini = min(mini, i);
				minj = min(minj, j);
				maxi = max(maxi, i);
				maxj = max(maxj, j);
			}
		}
	}
	cout << (1 + max(maxi-mini,maxj-minj)) << endl;

}