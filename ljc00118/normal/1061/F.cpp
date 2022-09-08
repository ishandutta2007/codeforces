#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

vector <int> t;
string qwq;
int n, k, zt = 0, dep;

int getdis(int x, int y) {
	if(x == y) return 0;
	int ans = 0; t.clear();
	for(register int i = 1; i <= n; i++) {
//		if(i == x || i == y) continue;
		cout << "? " << x << " " << i << " " << y << endl;
		cin >> qwq;
		if(qwq == "Yes") ans++, t.push_back(i);
	}
	return ans - 1;
}

int getdis2(int x, int y) {
	if(x == y) return 0;
	int ans = 0;
	for(register int i = 0; i < dep * 2 + 1; i++) {
//		if(i == x || i == y) continue;
		cout << "? " << x << " " << t[i] << " " << y << endl;
		cin >> qwq;
		if(qwq == "Yes") ans++;
	}
	return ans - 1;
}

int main() {
	srand(20050426);
	ios::sync_with_stdio(false); cin.tie(0); cin >> n >> k; int x, y, sum = 1, now = 1;
	while(sum != n) now *= k, sum += now, dep++;
	while(1) {
		x = rand() % n + 1, y = rand() % n + 1;
		if(getdis(x, y) == dep * 2) break;
	}
	for(register int i = 0; i < dep * 2 + 1; i++) {
		if(getdis2(x, t[i]) == dep) {
			cout << "! " << t[i] << endl;
			return 0;
		}
	}
	return 0;
}