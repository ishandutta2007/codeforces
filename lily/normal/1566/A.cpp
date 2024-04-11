#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
void read(int &a) {scanf("%d", &a);}
void read(LL &a) {scanf("%lld", &a);}

int main() {
	int T;
	read(T);
	while (T--) {
		int n, s;
		read(n); read(s);
		int cnt = (n + 2) / 2;
		cout << s / cnt << endl;
	}
}