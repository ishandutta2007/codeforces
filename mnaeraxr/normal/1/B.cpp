#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool isNum(char c){
	return '0' <= c && c <= '9';
}

bool detect(string &s){
	for (int i = 0; i + 1 < s.length(); ++i)
		if (isNum(s[i]) && !isNum(s[i + 1])) return true;
	return false;
}

int tot[100], ac[100];

void convert1(string &s){
	bool b = true;
	int r = 0, c = 0;
	for (int i = 1; i < s.length(); ++i){
		if (!isNum(s[i])) b = false;
		else{
			int v = s[i] - '0';
			if (b) r = r * 10 + v;
			else c = c * 10 + v;
		}
	}
	int d = 0;
	while (c > ac[d]) ++d;
	c -= ac[d - 1];
	for (int i = 0; i < d; ++i){
		int cur = tot[d - i - 1];
		int val = 0;
		while (c > cur * (val + 1)) ++val;
		c -= cur * val;
		cout << (char)('A' + val);
	}
	cout << r << endl;
}

void convert2(string &s){
	int p = 0;
	while (!isNum(s[p])) ++p;
	int c = 0;
	for (int i = 0; i < p; ++i)
		c = c * 26 + s[i] - 'A';
	c = c + ac[p - 1] + 1;
	int r = 0;
	for (int i = p; i < s.length(); ++i)
		r = r * 10 + (s[i] - '0');
	cout << "R" << r << "C" << c << endl;
}

void solve(){
	string s; cin >> s;
	bool mode = detect(s);
	if (mode) convert1(s);
	else convert2(s);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	tot[0] = 1;
	ac[0] = 0;
	for (int i = 1; i < 100; ++i){
		tot[i] = 26 * tot[i - 1];
		ac[i] = ac[i - 1] + tot[i];
	}

	int t; cin >> t;
	while(t--) solve();

	return 0;
}