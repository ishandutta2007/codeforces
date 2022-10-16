#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

typedef long long LL;

const int N = 105;

void inline ask(int l, int r) {
	cout << "? " << l << " " << r << endl;
 	cout.flush();
}

int n, tot, cnt[300], sum[300];

string a[N];

bool inline cmp(string x, string y) {
	return x.size() < y.size();
}

multiset<string> s;

void inline add(string b) {
	for (int i = 0; i < b.size(); i++)
		sum[b[i] - 'a']++;
	char c;
	for (int i = 0; i < 26; i++) {
		if (sum[i] != cnt[i]) {
			c = i + 'a';
			cnt[i]++;
		}
		sum[i] = 0;
	}
	cout << c;
}

int main() {
	cin >> n;
	if (n == 1) {
		ask(1, 1);
		string t; cin >> t;
		cout << "! " << t << endl;
		fflush(stdout);
	} else {
		ask(1, n);
		for (int i = 1; i <= n * (n + 1) / 2; i++) {
			string t; cin >> t;
			sort(t.begin(), t.end());
			s.insert(t);
		}
		ask(2, n);
		for (int i = 1; i <= n * (n - 1) / 2; i++) {
			string t; cin >> t;
			sort(t.begin(), t.end());
			s.erase(s.find(t));
		}
		for (auto t: s){
			a[++tot] = t;
		}
		sort(a + 1, a + 1 + n, cmp);
		cout << "! ";
		for (int i = 1; i <= n; i++) { 
			add(a[i]);
		}
		cout << endl;
		cout.flush();
	}
	return 0;
}