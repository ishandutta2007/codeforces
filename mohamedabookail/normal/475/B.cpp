/**
*    author:  Mohamed Abo Okail
*    created: 19/O8/2O21
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl "\n";
 
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	int cnt1 = 0, cnt2 = 0;
	if(a[0] != a.back() && b[0] != b.back()) cnt1++;
	if(a[0] == '<') cnt2++;
	if(b[0] == 'v') cnt2++;
	cout << (cnt1 == 1 && (cnt2 == 0 || cnt2 == 2) ? "YES" : "NO") << endl;
}