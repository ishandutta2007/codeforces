#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	string stuff[n];
	for(int i = 0; i < n; i++){
		cin >> stuff[i];
	}
	int r[m];
	for(int i = 0; i < m; i++){
		r[i] = 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(stuff[i][j] == '.'){
				r[j]++;
			}
		}
	}
	int a = 0;
	int b = 0;
	for(int i = 0; i < m-1; i++){
		a = max(a,r[i]-r[i+1]);
		b = min(b,r[i]-r[i+1]);
	}
	cout << a << " " << -b << endl;

}