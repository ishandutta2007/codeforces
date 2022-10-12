/**
*    author:  Mohamed Abo_Okail
*    created: O1/11/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		int flag = n - i * i;
		if(i + flag * flag == m && flag >= 0) cnt++;
	}
	cout << cnt << endl;
}