/*input
0
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N
#define bit(x,y) ((x>>y)&1LL)
#define For(i,l,r) for(int i=l; i<r; i++)

bool check[8];
vector<string> alls;
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	memset(check, 0, sizeof(check));
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if (s == "purple") check[1] = true;
		else if (s == "green") check[2] = true;
		else if (s == "blue") check[3] = true;
		else if (s == "orange")check[4] = true;
		else if (s == "red") check[5] = true;
		else if (s == "yellow")check[6] = true;
	}
	for (int i = 1; i <= 6; i++) {
		if (check[i]) continue;
		if (i == 1) alls.push_back("Power");
		else if (i == 2) alls.push_back("Time");
		else if (i == 3) alls.push_back("Space");
		else if (i == 4) alls.push_back("Soul");
		else if (i == 5) alls.push_back("Reality");
		else if (i == 6) alls.push_back("Mind");
	}
	cout << alls.size() << endl;
	for (auto it : alls) cout << it << endl;
}