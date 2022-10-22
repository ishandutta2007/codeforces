#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n, m, Q;
string s[25], t[25];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 0; i < m; i++) cin >> t[i];
	
	cin >> Q;
	llint x;
	for(int q = 1; q <= Q; q++){
		cin >> x;
		x--;
		cout << s[x%n] + t[x%m] << "\n";
	}
	flush(cout);
	
	return 0;
}