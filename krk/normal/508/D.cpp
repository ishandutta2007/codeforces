#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxl = 5;
const int Maxn = 200005;
const int Maxm = 10005;
const int Maxc = 62;

int n;
char s[Maxn][Maxl];
int in[Maxm];
vector <int> neigh[Maxm];
int seq[Maxn], slen;

int getId(char ch) 
{
	if (islower(ch)) return ch - 'a';
	else if (isupper(ch)) return ch - 'A' + 26;
	else return ch - '0' + 52;
}

char getChar(int id)
{
	if (id < 26) return 'a' + id;
	else if (id < 52) return 'A' + id - 26;
	else return '0' + id - 52;
}

int getId(char a, char b)
{
	return getId(a) * 62 + getId(b);
}

void Traverse(int v)
{
	if (neigh[v].size() == 0 && slen == n) seq[slen--] = v;
	while (neigh[v].size() > 0) {
		int u = neigh[v].back(); neigh[v].pop_back();
		Traverse(u);
		seq[slen--] = v;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]); 
		int a = getId(s[i][0], s[i][1]), b = getId(s[i][1], s[i][2]);
		neigh[a].push_back(b); in[b]++;
	}
	bool flag = false;
	int m1 = 0, st = -1;
	int l1 = 0;
	for (int i = 0; i < Maxm; i++)
		if (neigh[i].size() == in[i]) continue;
		else if (in[i] + 1 == neigh[i].size()) { m1++; st = i; }
		else if (in[i] - 1 == neigh[i].size()) l1++;
		else flag = true;
	if (m1 == 1 && l1 == 1 && !flag || m1 == 0 && l1 == 0 && !flag) {
		if (st == -1) { st = 0; while (neigh[st].empty()) st++; }
		slen = n;
		Traverse(st);
		if (slen < 0) {
			printf("YES\n");
			printf("%c", getChar(seq[0] / 62)); printf("%c", getChar(seq[0] % 62));
			for (int i = 1; i <= n; i++)
				printf("%c", getChar(seq[i] % 62));
			printf("\n");
		} else printf("NO\n");
	} else printf("NO\n");
	return 0;
}