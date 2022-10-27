#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a)


int n, x;

int main() {
	read(n); read(x);
	vector <int> a;
	for (int i = 1; i <= n; i++) {
		int y;
		read(y);
		if (y < x) a.push_back(y);
	}
	sort(a.begin(), a.end());
	vector <int> b;
	int i = 0, j = 0;
	while (i < a.size() || j < b.size()) {
		int w;
		if (i < a.size() && j < b.size()) {
			if (a[i] < b[j]) w = a[i++];
			else w = b[j++];
		} else if (i < a.size()) {
			w = a[i++];
		}
		else {
			assert (j < b.size());
			w = b[j++];
		}
		int kn = 1;
		while (kn <= w && i < a.size() && a[i] == w) kn++, i++; 
		while (kn <= w && j < b.size() && b[j] == w) kn++, j++; 
		if (kn != w + 1) {
			puts ("No");
			return 0;
		}
		if (w + 1 < x) b.push_back(w + 1);
	}
	puts ("Yes");
}