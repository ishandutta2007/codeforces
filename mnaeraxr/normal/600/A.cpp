 #include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 20;

bool isnum(string &s){
	if (s.length() == 0) return false;
	if (s[0] == '0') return s.length() == 1;
	for (auto c : s) if (c < '0' || c > '9') return false;
	return true;
}

void append(string &s, string c){
	s = s + c + ",";
}

void fix(string &s){
	if (s == "") s = "-";
	else{
		s = "\"" + s;
		s.back() = '\"';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	string ans1 = "", ans2 = "";
	string cur = "";
	s += ',';
	for (auto c : s){
		if (c == ',' || c == ';'){
			if (isnum(cur)) append(ans1, cur);
			else append(ans2, cur);
			cur = "";
		}
		else
			cur += c;
	}

	fix(ans1); fix(ans2);
	cout << ans1 << endl << ans2 << endl;

	return 0;
}