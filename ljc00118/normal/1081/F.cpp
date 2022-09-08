#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 305;

int a[N], s[N];
int n, t;

int query(int l, int r) {
	cout << "?" << " " << l << " " << r << endl; cout.flush();
	int ans; cin >> ans; return ans;
}

int calc1(int x) {
	int ans = t;
	if(x % 2 == 1) {
		int cnt = 0, last = t;
		for(register int i = 1; i <= 10000; i++) {
			int now = query(1, x);
			if(now % 2 != last % 2 && now % 2 != t % 2 && i % 2 == 1) { ans = last - now; cnt = i; break; }
			last = now;
		}
		while(1) {
			cnt++; int now = query(1, x);
			if(now == t && cnt % 2 == 0) break; 
		}
		return ((x + ans) >> 1) - s[x - 1];
	}
	if(x % 2 == 0) {
		int cnt = 0, last = t;
		for(register int i = 1; i <= 10000; i++) {
			int now = query(2, x);
			if(now % 2 == last % 2 && now % 2 == t % 2 && i % 2 == 1) { ans = last - now; cnt = i; break; }
			last = now;
		}
		while(1) {
			cnt++; int now = query(2, x);
			if(now == t && cnt % 2 == 0) break; 
		}
		return ((x + ans) >> 1) - s[x - 1];
	}
}

int calc2(int x) {
	int ans = t;
	if(x % 2 == 1) {
		int last = t, cnt = 0;
		for(register int i = 1; i <= 10000; i++) {
			int now = query(x - 1, x);
			if(now % 2 != last % 2 && now % 2 != t % 2 && i % 2 == 1) { ans = last - now; cnt = i; break; }
			last = now;
		}
		while(1) {
			cnt++; int now = query(x - 1, x);
			if(now == t && cnt % 2 == 0) break; 
		}
		return ((x + ans) >> 1) - s[x - 1];
	}
	if(x % 2 == 0) {
		int last = t, cnt = 0;
		for(register int i = 1; i <= 10000; i++) {
			int now = query(x - 1, x);
			if(now % 2 == last % 2 && now % 2 == t % 2 && i % 2 == 1) { ans = last - now; cnt = i; break; }
			last = now;
		}
		while(1) {
			cnt++; int now = query(x - 1, x);
			if(now == t && cnt % 2 == 0) break; 
		}
		return ((x + ans) >> 1) - s[x - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> t;
	if(n == 1) {
		cout << "!" << " ";
		cout << t << endl;
		return 0;
	}
	if(n % 2 == 0) {
		for(register int i = 1; i < n; i++) {
			a[i] = calc1(i);
			s[i] = s[i - 1] + a[i];
		}
		if(s[n - 1] != t) a[n] = 1;
		cout << "!" << " ";
		for(register int i = 1; i <= n; i++) cout << a[i];
		cout << endl; cout.flush();
		return 0;
	}
	int last = t, cnt = 0;
	for(register int i = 1; i <= 10000; i++) {
		int now = query(2, n);
		if(now % 2 == last % 2 && now % 2 == t % 2 && i % 2 == 1) {
//			printf("t = %d, last = %d, now = %d\n", t, last, now);
			a[1] = s[1] = t - (n - 1 + last - now) / 2;
			cnt = i; break;
		}
		last = now;
	}
	while(1) {
		cnt++; int now = query(2, n);
		if(now == t && cnt % 2 == 0) break;
	}
	for(register int i = 2; i < n; i++) {
		a[i] = calc2(i);
		s[i] = s[i - 1] + a[i];
	}
	if(s[n - 1] != t) a[n] = 1;
	cout << "!" << " ";
	for(register int i = 1; i <= n; i++) cout << a[i];
	cout << endl; cout.flush();
	return 0;
}

// Rotate Flower Round.