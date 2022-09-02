#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;

	int vert = 0;
	int hori = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '0') {
			cout << 1 << ' ' << vert+1 << '\n';
			vert = (vert + 1) % 4;
		} else {
			cout << 3 << ' ' << 2*hori+1 << '\n';
			hori = (hori + 1) % 2;
		}
	}
}