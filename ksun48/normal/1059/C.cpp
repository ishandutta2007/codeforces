#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(int n, int k){
	if(n == 1){
		cout << k << endl;
		return;
	}
	if(n == 2){
		cout << k << " " << 2*k << endl;
		return;
	}
	if(n == 3){
		cout << k << " " << k << " " << 3*k << endl;
		return;
	}
	for(int i = 1; i <= n; i += 2){
		cout << k << " ";
	}
	solve(n/2, k*2);
}

int main(){
	int n;
	cin >> n;
	solve(n, 1);
}