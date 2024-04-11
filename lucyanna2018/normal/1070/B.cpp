#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<utility>
using namespace std;
#define u32 unsigned int
struct Node {
	int l, r, typ;
	bool has_todo, has_not_todo;
} a[202222 * 34];
int Z;
bool bad(int x, int cur_typ) {
	if (x == 0)return false;
	if (a[x].typ) {
		if (cur_typ != 0 && cur_typ != a[x].typ)
			return true;
		cur_typ = a[x].typ;
	}
	return bad(a[x].l, cur_typ) || bad(a[x].r, cur_typ);
}
void dfs(int x) {
	if (x == 0)return;
	if (a[x].typ == -1)
		a[x].has_todo = true;
	else
	if (a[x].typ == 1)
		a[x].has_not_todo = true;
	dfs(a[x].l);
	dfs(a[x].r);
	a[x].has_todo |= a[a[x].l].has_todo;
	a[x].has_todo |= a[a[x].r].has_todo;
	a[x].has_not_todo |= a[a[x].l].has_not_todo;
	a[x].has_not_todo |= a[a[x].r].has_not_todo;
}
vector<pair<u32, int> > res;
void dfs2(int x,u32 cur,int c4) {
	if (x == 0)return;
	if (a[x].typ == -1) {
		res.push_back(make_pair(cur, c4));
		return;
	}
	if (a[x].typ == 1)return;
	if (a[x].has_todo && !a[x].has_not_todo) {
		res.push_back(make_pair(cur, c4));
		return;
	}
	dfs2(a[x].l, cur * 2, c4 - 1);
	dfs2(a[x].r, cur * 2 + 1, c4 - 1);
}
int main() {
	ios::sync_with_stdio(false);
	int _;
	char s[99];
	Z = 1;
	for (scanf("%d", &_); _--;) {
		scanf("%s", s);
		string S;
		for (int i = 1; s[i]; i++)
			if (s[i] == '.' || s[i] == '/')
				S += " ";
			else
				S += s[i];
		int c[5], lc = 0;
		istringstream sin(S);
		while (sin >> c[lc])lc++;
		if (lc == 4)c[lc++] = 32;
		u32 cur = 0;
		for (int i = 0; i < 4; i++)
			cur = (cur << 8) + c[i];
		int pnt = 1;
		for (int i = 31, j = 0; j < c[4]; i--, j++) {
			if (cur & (((u32)1) << i)) {
				if (a[pnt].r == 0) 
					a[pnt].r = ++Z;
				pnt = a[pnt].r;
			}
			else {
				if (a[pnt].l == 0)
					a[pnt].l = ++Z;
				pnt = a[pnt].l;
			}
		}
		int cur_typ = (s[0] == '+' ? 1 : -1);
		if (a[pnt].typ != 0) {
			if (a[pnt].typ != cur_typ) {
				cout << "-1" << endl;
				return 0;
			}
		}
		else
			a[pnt].typ = cur_typ;
	}
	if (bad(1, 0)) {
		cout << "-1" << endl;
		return 0;
	}
	dfs(1);
	dfs2(1, 0, 32);
	int m = res.size();
	cout << m << endl;
	for (int i = 0; i < m; i++) {
		u32 w = res[i].first << res[i].second, a[4];
		for (int i = 3; i >= 0; i--) {
			a[i] = w & 255;
			w >>= 8;
		}
		for (int i = 0; i < 3; i++)
			cout << a[i] << ".";
		cout << a[3] << "/" << 32-res[i].second << endl;
	}
	return 0;
}