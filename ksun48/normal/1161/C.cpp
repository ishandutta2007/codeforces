#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int v = 1e6;
	for(int i = 0; i < n; i++){
		v = min(v, a[i]);
	}
	int mfreq = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == v) mfreq++;
	}
	if(mfreq <= n/2){
		cout << "Alice" << '\n';
	} else {
		cout << "Bob" << '\n';
	}
}