#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

vector <string> seq;
int T;
int n;
string str;
char tmp[Maxn];

void Read(string &s)
{
	scanf("%s", tmp);
	s = tmp;
}

bool Less(const string &a, const string &b)
{
	if (a.length() != b.length()) return a.length() < b.length();
	return a < b;
}

int main()
{
	for (char a = 'a'; a <= 'z'; a++) {
		string s = string(1, a);
		seq.push_back(s);
		for (char b = 'a'; b <= 'z'; b++) {
			s = string(1, a) + string(1, b);
			seq.push_back(s);
			for (char c = 'a'; c <= 'z'; c++) {
				s = string(1, a) + string(1, b) + string(1, c);
				seq.push_back(s);
			}
		}
	}
	sort(seq.begin(), seq.end(), Less);
	scanf("%d", &T);
	while (T--) {
		set <string> S;
		scanf("%d", &n);
		Read(str);
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= 3 && i + j <= n; j++)
				S.insert(str.substr(i, j));
		for (int i = 0; i < seq.size(); i++)
			if (S.find(seq[i]) == S.end()) {
				printf("%s\n", seq[i].c_str());
				break;
			}
	}
    return 0;
}