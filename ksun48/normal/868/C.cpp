#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, k;
	cin >> n >> k;
	int f[16];
	for(int i = 0; i < 16; i++) f[i] = 0;
	for(int i = 0; i < n; i++){
		int c = 0;
		for(int j = 0; j < k; j++){
			c *= 2;
			int a;
			cin >> a;
			c += a;
		}
		f[c]++;
	}
	int ok = 0;
	if(f[0] != 0) ok = 1;
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			if(i == j) continue;
			if(f[i] == 0 || f[j] == 0) continue;
			if((i & j) == 0) ok = 1;
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}