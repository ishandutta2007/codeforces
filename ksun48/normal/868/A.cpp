#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string p;
	cin >> p;
	int n;
	cin >> n;
	string a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int ok = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == p) ok = 1;
		for(int j = 0; j < n; j++){
			if(p[0] == a[i][1] && p[1] == a[j][0]){
				ok = 1;
			}
		}
	}
	cout << (ok ? "YES" : "NO") << endl;
}