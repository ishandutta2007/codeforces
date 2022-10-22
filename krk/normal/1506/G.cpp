#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxl = 26;

int T;
char str[Maxn];
int slen;
deque <int> seq[Maxl];
char res[Maxn];
int rlen;

bool Check(int x)
{
	if (seq[x].empty()) return false;
	for (int i = 0; i < Maxl; i++) if (!seq[i].empty() && i != x)
		if (seq[i].back() < seq[x].front()) return false;
	return true;
}

void Write(int x)
{
	res[rlen++] = 'a' + x;
	for (int i = 0; i < Maxl; i++) if (!seq[i].empty() && i != x)
		while (seq[i].front() < seq[x].front())
			seq[i].pop_front();
	seq[x].clear();
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		slen = strlen(str);
		for (int i = 0; i < Maxl; i++)
			seq[i].clear();
		rlen = 0;
		for (int i = 0; i < slen; i++)
			seq[str[i] - 'a'].push_back(i);
		while (true) {
			int i = Maxl - 1;
			while (i >= 0 && !Check(i)) i--;
			if (i < 0) break;
			Write(i);
		}
		res[rlen] = '\0';
		printf("%s\n", res);
	}
    return 0;
}