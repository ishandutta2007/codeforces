#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>
using namespace std;

int n;
map <string, int> M;
int res = 1;

void Fix(string &s)
{
	for (int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);
}

int main()
{
	M["polycarp"] = 1;
	cin >> n;
	string a, b, tmp;
	while (n--) {
		cin >> a >> tmp >> b; Fix(a); Fix(b);
		M[a] = M[b] + 1;
		res = max(res, M[a]);
	}
	cout << res << endl;
	return 0;
}