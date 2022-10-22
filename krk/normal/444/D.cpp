#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 50005;
const int Maxl = 4;
const int Maxm = 476000;
const int Maxq = 100005;
const int Maxp = 450;

map <string, int> M;
string nam[Maxm];
int nlen;
char s[Maxn];
int slen;
vector <int> inds[Maxm];
int q;
int a[Maxq], b[Maxq], res[Maxq];
vector <ii> solveBig[Maxm];
int tmpres[Maxm];
vector <int> inpos[Maxn];

int getIDInsert(const string &s)
{
	if (M.find(s) == M.end()) {
		M[s] = nlen; nam[nlen++] = s;
	}
	return M[s];
}

int getID(const string &s)
{
	if (M.find(s) != M.end())
		return M[s];
	return -1;
}

bool isPartOf(const string &a, const string &b)
{
	if (a.length() > b.length()) return false;
	for (int i = 0; i + a.length() <= b.length(); i++)
		if (a == b.substr(i, a.length())) return true;
	return false;
}

int solveSmall(int a, int b)
{
	int i = 0, j = 0;
	int res = Maxn;
	while (i < inds[a].size() && j < inds[b].size())
		if (inds[a][i] < inds[b][j]) {
			res = min(res, inds[b][j] + int(nam[b].length()) - inds[a][i]);
			i++;
		} else {
			res = min(res, inds[a][i] + int(nam[a].length()) - inds[b][j]);
			j++;
		}
	return res;
}

void solveForw(int a)
{
	int cur = -Maxn;
	int j = 0;
	for (int i = 0; i < slen; i++) {
		if (j < inds[a].size() && inds[a][j] == i) { cur = i; j++; }
		for (int k = 0; k < inpos[i].size(); k++) {
			int b = inpos[i][k];
			tmpres[b] = min(tmpres[b], i + int(nam[b].length()) - cur);
		}
	}
}

void solveBack(int a)
{
	int cur = 2 * Maxn;
	int j = inds[a].size() - 1;
	for (int i = slen - 1; i >= 0; i--) {
		if (j >= 0 && inds[a][j] == i) { cur = i; j--; }
		for (int k = 0; k < inpos[i].size(); k++) {
			int b = inpos[i][k];
			tmpres[b] = min(tmpres[b], cur + int(nam[a].length()) - i);
		}
	}
}

int main()
{
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &q);
	char tmp[Maxl + 3];
	for (int i = 0; i < q; i++) {
		scanf("%s", tmp); a[i] = getIDInsert(tmp); 
		scanf("%s", tmp); b[i] = getIDInsert(tmp);
		res[i] = Maxn;
	}
	for (int i = 0; i < slen; i++) {
		char toget[Maxl + 3];
		for (int j = 0; j < Maxl && i + j < slen; j++) {
			toget[j] = s[i + j]; toget[j + 1] = '\0';
			int id = getID(toget);
			if (id != -1) inds[id].push_back(i);
		}
	}
	for (int i = 0; i < q; i++)
		if (isPartOf(nam[a[i]], nam[b[i]])) {
			if (!inds[b[i]].empty()) res[i] = nam[b[i]].length();
		} else if (isPartOf(nam[b[i]], nam[a[i]])) {
			if (!inds[a[i]].empty()) res[i] = nam[a[i]].length();
		} else if (inds[a[i]].size() >= Maxp) solveBig[a[i]].push_back(ii(b[i], i));
		  	   else if (inds[b[i]].size() >= Maxp) solveBig[b[i]].push_back(ii(a[i], i));
		  	   	    else res[i] = solveSmall(a[i], b[i]);
	fill(tmpres, tmpres + nlen, Maxn + 1);
	for (int i = 0; i < nlen; i++)
		if (!solveBig[i].empty()) {
			for (int j = 0; j < solveBig[i].size(); j++) {
				int b = solveBig[i][j].first;
				if (tmpres[b] > Maxn) {
					tmpres[b] = Maxn;
					for (int k = 0; k < inds[b].size(); k++)
						inpos[inds[b][k]].push_back(b);
				}
			}
			solveForw(i);
			solveBack(i);
			for (int j = 0; j < solveBig[i].size(); j++) {
				int b = solveBig[i][j].first;
				res[solveBig[i][j].second] = tmpres[b];
			}
			for (int j = 0; j < solveBig[i].size(); j++) {
				int b = solveBig[i][j].first;
				if (tmpres[b] <= Maxn) {
					tmpres[b] = Maxn + 1;
					for (int k = 0; k < inds[b].size(); k++)
						inpos[inds[b][k]].clear();
				}
			}
		}
	for (int i = 0; i < q; i++)
		printf("%d\n", res[i] >= Maxn? -1: res[i]);
	return 0;
}