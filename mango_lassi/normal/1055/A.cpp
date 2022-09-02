#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1000;
bool open1[N];
bool open2[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, s;
	cin >> n >> s;
	--s;

	for (int i = 0; i < n; ++i) cin >> open1[i];
	for (int i = 0; i < n; ++i) cin >> open2[i];

	int lst = -1;
	for (int i = 0; i < n; ++i) {
		if (open1[i] && open2[i]) lst = i;
	}	

	if (! open1[0]) {
		cout << "NO\n";
	} else {
		if (open1[s] || lst >= s && open2[s]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}