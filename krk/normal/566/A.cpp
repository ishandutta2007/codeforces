#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxm = 800005;
const int Maxn = 100005;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 37;
const int arg2 = 1000007;

char tmp[Maxm];
map <ii, vector <int> > M[Maxm];
int n;
string names[Maxn], pseudo[Maxn];
vector <ii> my[Maxn];
vector <int> bylen;
bool tknam[Maxn], tkps[Maxn];
ll res;
vector <ii> seq;

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

bool Less(const int &a, const int &b)
{
	return names[a].length() > names[b].length();
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Read(names[i]); bylen.push_back(i);
		ii h = ii(0, 0); my[i].push_back(h);
		for (int j = 0; j < names[i].length(); j++) {
			h.first = (ll(h.first) * arg1 + ll(names[i][j] - 'a' + 1)) % mod1;
			h.second = (ll(h.second) * arg2 + ll(names[i][j] - 'a' + 1)) % mod2;
			my[i].push_back(h);
		}
	}
	for (int i = 0; i < n; i++) {
		Read(pseudo[i]);
		ii h = ii(0, 0); M[0][h].push_back(i);
		for (int j = 0; j < pseudo[i].length(); j++) {
			h.first = (ll(h.first) * arg1 + ll(pseudo[i][j] - 'a' + 1)) % mod1;
			h.second = (ll(h.second) * arg2 + ll(pseudo[i][j] - 'a' + 1)) % mod2;
			M[j + 1][h].push_back(i);
		}
	}
	sort(bylen.begin(), bylen.end(), Less);
	int pnt = 0;
	for (int i = Maxm - 1; i >= 0; i--) {
		while (pnt < n && i <= names[bylen[pnt]].length()) pnt++;
		for (int j = 0; j < pnt; j++) if (!tknam[bylen[j]]) {
			ii h = my[bylen[j]][i];
			map <ii, vector <int> >::iterator it = M[i].find(h);
			if (it != M[i].end()) {
				while (!it->second.empty() && tkps[it->second.back()]) it->second.pop_back();
				if (!it->second.empty()) {
					res += i; tknam[bylen[j]] = true; tkps[it->second.back()] = true;
					seq.push_back(ii(bylen[j], it->second.back()));
				}
			}
		}
	}
	printf("%I64d\n", res);
	for (int i = 0; i < seq.size(); i++)
		printf("%d %d\n", seq[i].first + 1, seq[i].second + 1);
	return 0;
}