#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
long long solve(vector<int> a){
	int d = 0;
	vector<int> vis(a.size(), 0);
	for(int i = 0; i < a.size(); i++){
		if(vis[i]) continue;
		int b = i;
		int num = 0;
		while(vis[b] == 0){
			vis[b] = 1;
			b = a[b];
			num++;
		}
		if(num % 2 == 0){
			d++;
		}
	}
	return d;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> perm(n, 0);
	for(int i = 0; i < n; i++){
		cin >> perm[i];
		perm[i]--;
	}
	int b = solve(perm);
	if(b % 2 == (3*n) % 2){
		cout << "Petr" << endl;
	} else {
		cout << "Um_nik" << endl;
	}
}