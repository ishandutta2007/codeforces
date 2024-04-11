#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	string p, t;
	cin >> t >> p;
	int n = t.size();
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	int inv[n];
	for(int i = 0; i < n; i++){
		inv[a[i]-1] = i+1;
	}
	int s = 0;
	int e = n;
	while(s + 1 < e){
		int m = (s+e)/2;
		int r = 0;
		for(int i = 0; i < n; i++){
			if(r == p.size()) break;
			if(inv[i] <= m) continue;
			if(p[r] == t[i]) r++;
		}
		if(r == p.size()){
			s = m;
		} else {
			e = m;
		}
	}
	cout << s << endl;
}