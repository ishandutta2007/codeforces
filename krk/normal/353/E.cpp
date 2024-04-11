#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int Maxn = 1000005;

char s[Maxn];
int n;
vector <int> seq;
int res;

int getRes1()
{
	int res = 0;
	int ind = (seq[1] + 1) % n, cur = 2 % seq.size();
	while (cur && (cur != seq.size() - 1 || ind != seq[cur])) {
		res++;
		if (ind != seq[cur]) { ind = (seq[cur] + 1) % n; cur = (cur + 1) % seq.size(); }
		else { ind = (seq[(cur + 1) % seq.size()] + 1) % n; cur = (cur + 2) % seq.size(); }
	}
	return res;
}

int getRes2()
{
	int res = 0;
	int ind = (seq[0] + 1) % n, cur = 1 % seq.size();
	do {
		res++;
		if (ind != seq[cur]) { ind = (seq[cur] + 1) % n; cur = (cur + 1) % seq.size(); }
		else { ind = (seq[(cur + 1) % seq.size()] + 1) % n; cur = (cur + 2) % seq.size(); }
	} while (cur != 1 && (cur != 0 || ind != seq[cur]));
	return res;
}

int main()
{
	scanf("%s", s); n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] != s[(i - 1 + n) % n]) 
			seq.push_back(i);
	res = max(1 + getRes1(), getRes2());
	printf("%d\n", res);
	return 0;
}