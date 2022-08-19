#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	int a = 0;
	for(int i = 0; i < n; i++){
		int r;
		cin >> r;
		a += r;
	}
	cout << a << '\n';
}