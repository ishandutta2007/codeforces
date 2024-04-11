#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define par pair<int, int>
#define poly vector<int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
int px = 0, py = 0, cnt = 0;
string ask(int x, int y) {
	cnt++;
	assert(cnt <= 130);
	px = x, py = y;
	cout << px <<" " << py << endl;
	string step;
	cin >> step;
	return step;
}

void solve() {
	cnt = px = py = 0;
	for(int i = 1; i <= 7; i++) {
		for(int j = (py == 1) + 1; j <= 8; j++) {
			string a = ask(i, j);
			if(a == "Done") return;
			if(a == "Up" || a == "Up-Left" || a == "Up-Right") {
				if(j > 1) j = 0;
			}
			if(a == "Down" || a == "Down-Left" || a == "Down-Right") {
				if(ask(i + 1, j) == "Done") {
					return;
				}
				break;
			}
		}
		if(px == i) {
			if(ask(px + 1, py) == "Done") {
				return;
			}
		}
	}
	return;
}

int main() {
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}