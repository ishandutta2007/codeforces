#include <iostream>
using namespace std;

const int N = 10000;
int pare[N];
bool leaf[N];
int kids[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> pare[i];
		--pare[i];
		leaf[pare[i]] = false;
		leaf[i] = true;
	}
	for (int i = 1; i < n; ++i) {
		if (leaf[i]) ++kids[pare[i]];
	}
	bool is = true;
	for (int i = 0; i < n; ++i) {
		if (leaf[i]) continue;
		if (kids[i] < 3) is = false;
	}
	if (is) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}