#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> deg(n, 0);
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		deg[a]++;
		deg[b]++;
	}
	bool works = true;
	for(int i = 0; i < n; i++){
		if(deg[i] == 2) works = false;
	}
	cout << (works ? "YES" : "NO") << '\n';
}