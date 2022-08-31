#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	int asum = 0;
	for(int x : a) asum ^= x;
	if(asum){
		cout << "NO" << '\n';
		return;
	}
	vector<int> b(n+1);
	b[0] = a[0];
	for(int i = 0; i < n-1; i++){
		b[i+1] = a[i+1] ^ a[i];
	}
	b[n] = a[n-1];
	vector<int> steps;
	if(n & 1){
		// n odd
		for(int i = 0; i <= n-3; i += 2) steps.push_back(i);
		for(int i = n-3; i >= 0; i -= 2) steps.push_back(i);
	} else {
		int split = -1;
		int psum = 0;
		for(int i = 0; i < n; i += 2){
			psum ^= b[i];
			if(psum == 0){
				split = i;
				break;
			}
		}
		if(split == -1){
			cout << "NO" << '\n';
			return;
		}
		for(int i = split-2; i >= 0; i -= 2){
			steps.push_back(i);
		}
		for(int i = split+2; i < n; i += 2){
			steps.push_back(i-1);
		}
		for(int i = 0; i < n-2; i += 2){
			steps.push_back(i);
		}
	}
	cout << "YES" << '\n';
	cout << steps.size() << '\n';
	for(int x : steps){
		cout << (x+1) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}