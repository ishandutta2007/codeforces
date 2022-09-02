#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void printCoord(int i, int w) {
	cout << (i/w)+1 << ' ' << (i%w)+1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	int i = 0;
	int j = h*w - 1;
	while(i <= j) {
		printCoord(i, w);
		if (j > i) printCoord(j, w);
		++i;
		--j;
	}
}