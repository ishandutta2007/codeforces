#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	int n = str.size();

	int a = 0;
	int b = n-1;
	while(true) {
		if (str[a] != str[b]) {
			cout << 0 << '\n';
			break;
		}
		int cou = 2;
		while(a+1 <= b && str[a+1] == str[a]) {
			++cou;
			++a;
		}
		while(b-1 >= a && str[b-1] == str[b]) {
			++cou;
			--b;
		}
		if (b <= a) {
			if (cou >= 3) cout << cou << '\n';
			else cout << 0 << '\n';
			break;
		} else if (cou < 3) {
			cout << 0 << '\n';
			break;
		}
		++a;
		--b;
	}
}