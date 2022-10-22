#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int Maxn = 1000006;
const int Maxk = 2005;

char p[Maxn];
int plen;
char s[Maxn];
int slen;
int k;
vector <char> gives[Maxk];
vector <char> getfrom[Maxk];
string res = "-";

int main()
{
	cin.getline(p, Maxn); plen = strlen(p);
	cin.getline(s, Maxn); slen = strlen(s);
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		for (int j = i; j < plen; j += k)
			gives[i].push_back(p[j]);
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < k; j++) getfrom[j].clear();
		for (int j = 0; j < slen; j++)
			getfrom[j % i].push_back(s[j]);
		string cand(k, '0');
		int cur = i - 1;
		for (int j = k - 1; j >= 0 && cur >= 0; j--)
			if (gives[j] == getfrom[cur]) { cand[j] = '1'; cur--; }
		if (cur < 0 && (res == "-" || cand < res)) res = cand;
	}
	printf("%s\n", res == "-"? "0": res.c_str());
	return 0;
}