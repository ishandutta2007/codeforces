#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int Maxn = 1005;

int n;
string procedureName[Maxn];
vector <string> params[Maxn];
int m;
map <string, string> variab;
int k;
string nam;
vector <string> curpars;
int res;

bool Equal(int v)
{
	if (procedureName[v] != nam || params[v].size() != curpars.size()) return false;
	for (int i = 0; i < params[v].size(); i++) {
		string par = params[v][i];
		if (par != "T" && par != variab[curpars[i]]) return false;
	}
	return true;
}

int main()
{
	string lin;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> lin; getline(cin, lin);
		int p = lin.find_first_not_of(" ");
		int nxt = lin.find_first_of(" (", p + 1);
		procedureName[i] = lin.substr(p, nxt - p);
		p = lin.find_first_not_of(" (", nxt + 1);
		while (p != string::npos) {
			nxt = lin.find_first_of(" ,)", p + 1);
			params[i].push_back(lin.substr(p, nxt - p));
			p = lin.find_first_not_of(" ,)", nxt + 1);
		}
	}
	scanf("%d", &m);
	while (m--) {
		string typ, nam; cin >> typ >> nam;
		variab[nam] = typ;
	}
	scanf("%d", &k); getline(cin, lin);
	while (k--) {
		getline(cin, lin);
		int p = lin.find_first_not_of(" ");
		int nxt = lin.find_first_of(" (", p + 1);
		nam = lin.substr(p, nxt - p);
		curpars.clear();
		p = lin.find_first_not_of(" (", nxt + 1);
		while (p != string::npos) {
			nxt = lin.find_first_of(" ,)", p + 1);
			curpars.push_back(lin.substr(p, nxt - p));
			p = lin.find_first_not_of(" ,)", nxt + 1);
		}
		res = 0;
		for (int i = 0; i < n; i++)
			res += Equal(i);
		printf("%d\n", res);
	}
	return 0;
}