#include <bits/stdc++.h>
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

const int N = 1e5 + 5;

vector <int> ans;
int a[N];
int n, k, sum;

int main() {
	cin >> n >> k;
	for(register int i = 1; i <= n; i++) {
		read(a[i]);
		sum += a[i];
	}
	if(sum % k != 0) {
		cout << "No" << endl;
		return 0;
	}
	sum /= k; int now = 0;
	for(register int i = 1; i <= n; i++) {
		now += a[i];
		if(now > sum) {
			cout << "No" << endl;
			return 0;
		}
		if(now == sum) {
			ans.push_back(i);
			now = 0;
		}
	}
	puts("Yes");
	int len = ans.size(); printf("%d ", ans[0]);
	for(register int i = 1; i < len; i++) printf("%d ", ans[i] - ans[i - 1]);
	return 0;
}