#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define read(a) scanf("%d", &a);

bool query (vector <int> a) {
	cout << "? " << a.size();
	for (auto i  : a) cout << " " << i;
	cout << endl;
	string ans;
	cin >> ans;
	return ans == "YES";
}
bool query (int a) { return query ((vector <int>){a});}
bool query (vector <int> a, vector <int> b) { for (auto i : b) a.push_back(i); return query (a);}
void answer (int x) {
	cout << "! " << x << endl;
	string ans;
	cin >> ans;
	if (ans == ":)") exit(0);
}
void solve (vector <int> a, vector <int> ex);

void solve (vector <int> a) {
	if (a.size() < 3) {
		for (auto i : a) {
			answer (i);
			
		}
		assert (false);
	}
	if (a.size() == 3) {
		if (query (a[0]) ) {
			answer (a[0]);
			if (query (a[1])) answer(a[1]);
			else answer (a[2]);
		}
		else {
			if (query (a[0])) {
				answer (a[0]);
				if (query (a[1])) answer(a[1]);
				else answer (a[2]);
			}
			else solve ({a[1], a[2]});
		}
	}
	vector <int> w[4];
	for (int i = 0; i < (int)a.size(); i++) {
		w[i % 4].push_back(a[i]);
	}
	bool ret1 = query (w[0], w[1]), ret2 = query (w[0], w[2]);
	if (ret1 && ret2) solve (a, w[3]);
	else if (ret1 && !ret2) solve (a, w[2]); 
	else if (!ret1 && ret2) solve (a, w[1]);
	else solve (a, w[0]);
}
void solve (vector <int> a, vector <int> ex) {
	set <int> e;
	for (auto i : ex) e.insert (i);
	vector <int> b;
	for (auto i : a) if (!e.count(i)) b.push_back(i);
	solve (b);
}

int main() {
	int n;
	read(n);
	vector <int> a;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}
	solve (a);
}