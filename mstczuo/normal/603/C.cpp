# include <iostream>

using namespace std;

int ss[] = {0, 1, 0, 1, 2, 0, 2, 0};
int getsg1(int n) {
	if(n < 8) return ss[n];
	if(n & 1) return 0;
	int t = getsg1(n/2);
	if(t == 1) return 2;
	return 1;
}

int getsg0(int n) {
	if(n <= 2) return n;
	return ~n & 1;
}

int main() {
	int n, k;
	cin >> n >> k;
	int sg = 0;
	for(int i = 0; i < n; ++i) {
		int x; cin >> x;
		if(k & 1) sg ^= getsg1(x);
		else sg ^= getsg0(x);
	}
	if(sg) puts("Kevin");
	else puts("Nicky");
	return 0;
}