#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)

vector <LL> fib, sum;

bool check(vector <vector <int>> &b, int k)  {
	vector <int> cnt(k + 1);
	for (auto &i : b) {
		int last = -1;
		for (auto j : i) {
			if (last == j + 1) return false;
			last = j;
			if (cnt[j]) return false;
			cnt[j]++;
		}
	}
	while (k >= 0) if (!cnt[k--]) return false;
	return true;
}

int n;
void work() {
	read(n);
	LL su = 0;
	vector <int> a;
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		a.push_back(x);
		su += x;
	}
	int k = 0;
	for ( ; k < sum.size(); k++) {
		if (sum[k] == su) break;
	}
	if (k == sum.size()) {
		puts("NO");
		return;
	}
	vector < vector <int> > b;
	for (auto i : a) {
		vector <int> ws;
		for (int j = k; j >= 0; j--) {
			if (i >= fib[j]) {
				ws.push_back(j);
				i -= fib[j];
			}
		}
		b.push_back(ws);
	}
	if (check(b, k)) { puts ("YES"); return;}	
	for (auto& i : b) {
		if (i.back() & 1) {
			vector <int> tmp = i;
			tmp.pop_back();
			int w = i.back() - 1;
			while (w >= 0){
				tmp.push_back(w);
				w -= 2;
			}
			swap(tmp, i);
			if (check(b, k)) { puts ("YES"); return;}
			swap(tmp, i);
		}
	}
	puts ("NO");	
}

int main() {
	fib.push_back(1);
	fib.push_back(1);
	sum.push_back(1);
	sum.push_back(2);
	while (sum.back() < 1e11) {
		fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
		sum.push_back(sum.back() + fib.back());
	}
	int T;
	read(T);
	while (T--) work();
}