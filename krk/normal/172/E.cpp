#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxw = 1000005;
const int Maxn = 205;

string lin;
int pnt;
map <string, int> ID;
int id;
vector <ii> neigh[Maxw];
int m;
int n;
int x[Maxn];

int getID(const string &s)
{
	if (!ID.count(s)) ID[s] = ID.size() - 1;
	return ID[s];
}

bool getToken(int &num, int &st)
{
	if (pnt == lin.length()) return false;
	if (lin[pnt + 1] == '/') {
		st = 2;
		int nxt = lin.find('>', pnt + 2);
		num = getID(lin.substr(pnt + 2, nxt - (pnt + 2))); 
		pnt = nxt + 1;
		return true;
	}
	int nxt = lin.find_first_of("/>", pnt + 1);
	num = getID(lin.substr(pnt + 1, nxt - (pnt + 1)));
	if (lin[nxt] == '/') { st = 1; pnt = nxt + 2; }
	else { st = 0; pnt = nxt + 1; }
	return true;
}

void Traverse(int v)
{
	int num, st;
	while (getToken(num, st))
		if (st == 2) return;
		else {
			neigh[v].push_back(ii(id++, num));
			if (st == 0) Traverse(id - 1);
		}
}

int Get(int v, int num, int pnt)
{
	int res = 0;
	if (pnt == n && num == x[n - 1]) res++;
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		res += Get(u.first, u.second, pnt == n? n: pnt + (x[pnt] == u.second));
	}
	return res;
}

int main()
{
	getline(cin, lin);
	id = 1; Traverse(0);
	scanf("%d", &m); getline(cin, lin);
	while (m--) {
		getline(cin, lin);
		n = 0;
		for (int i = 0, j; i < lin.length(); i = j + 1) {
			j = i;
			while (j < lin.length() && lin[j] != ' ') j++;
			x[n++] = getID(lin.substr(i, j - i));
		}
		printf("%d\n", Get(0, -1, 0));
	}
	return 0;
}