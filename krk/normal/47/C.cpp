#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 6;

string w[Maxn];
vector <int> seq;
vector <string> res, cand;
bool was;

void H(vector <string> &cand, int r, int c, const string &w)
{
	for (int i = 0; i < w.length(); i++)
		cand[r][c + i] = w[i];
}

void V(vector <string> &cand, int r, int c, const string &w)
{
	for (int i = 0; i < w.length(); i++)
		cand[r + i][c] = w[i];
}

bool getVector(vector <string> &cand)
{
	if (w[seq[0]].length() + w[seq[5]].length() - 1 != w[seq[3]].length()) return false;
	if (w[seq[1]].length() + w[seq[4]].length() - 1 != w[seq[2]].length()) return false;
	int x1 = w[seq[0]].length() - 1, x2 = w[seq[3]].length() - 1;
	int y1 = w[seq[1]].length() - 1, y2 = w[seq[2]].length() - 1;
	if (w[seq[0]][0] != w[seq[1]][0] || w[seq[0]][x1] != w[seq[2]][0] || 
		w[seq[1]][y1] != w[seq[3]][0] || w[seq[2]][y1] != w[seq[3]][x1] || w[seq[4]][0] != w[seq[3]][x2] ||
		w[seq[2]][y2] != w[seq[5]][0] || w[seq[4]][y2 - y1] != w[seq[5]][x2 - x1]) return false;
	cand.assign(y2 + 1, string(x2 + 1, '.'));
	H(cand, 0, 0, w[seq[0]]); H(cand, y1, 0, w[seq[3]]); H(cand, y2, x1, w[seq[5]]);
	V(cand, 0, 0, w[seq[1]]); V(cand, 0, x1, w[seq[2]]); V(cand, y1, x2, w[seq[4]]);
	return true;
}

int main()
{
	for (int i = 0; i < Maxn; i++)
		cin >> w[i];
	for (int i = 0; i < Maxn; i++) seq.push_back(i);
	do if (getVector(cand) && (!was || cand < res)) { res = cand; was = true; }
	while (next_permutation(seq.begin(), seq.end()));
	if (!was) printf("Impossible\n");
	else for (int i = 0; i < res.size(); i++)
			printf("%s\n", res[i].c_str());
	return 0;
}