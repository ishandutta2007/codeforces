#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)


vector <string> get() {
	fflush(stdout);
	string x;
	cin >> x;
	if (x == "stop") exit(0);
	int c = x[0] - '0';
	vector<string> ret;
	while (c--) {
		cin >> x;
		ret.push_back(x);
	}
	return ret;
}

int C;

void solve() {
	for (int i = 1; ; i++) {
		printf("next 0 1 2 3 4 5 6 7 8 9\n");
		vector <string> a = get();
		for (auto v : a) {
			if (v.find('0') != -1 && v.find('2') != -1) {
				puts("done");
				fflush(stdout);
				exit(0);
				return;
			}
		}
	}
}

int main() {
	for (int i = 1; ; i++) {
		printf("next 0\n");
		vector <string> a = get();
		printf("next 0 1\n");
		a = get();
		for (auto v : a) {
			if (v.find('0') != -1 && v.find('1') != -1) {
				C = i;
				solve();
			}
		}
	}

	return 0;
}