#include <bits/stdc++.h>
using namespace std;

int T;
map <string, int> D;

string tolower(const string &s)
{
	string ret;
	for (char c: s){
		if (isalpha(c)) c = tolower(c);
		ret.push_back(c);
	}
	return ret;
}

int main()
{
	D["polycarp"] = 1;
	int ans = 1;
	for (cin >> T;T--;){
		string name1, tmp, name2;
		cin >> name1 >> tmp >> name2;
		name1 = tolower(name1);
		name2 = tolower(name2);
		int &v = D[name2], &dy = D[name1];
		if (v) dy = max(dy, v+1);
		ans = max(ans, v+1);
	}
	cout << ans << endl;
}