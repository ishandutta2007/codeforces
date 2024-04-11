#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long double ld;

typedef pair <ld, ld> ldld;
typedef pair <ldld, int> ldldi;

const int Maxn = 200005;
const ld eps = 1e-11l;

int n;
ldldi seq[Maxn];
ldld S[Maxn];
int Slen;
set <ldld> St;
vector <int> res;

bool Less(const ldldi &a, const ldldi &b)
{
	if (a.first.second != b.first.second) return a.first.second < b.first.second;
	return a.first.first < b.first.first;
}

ld Cross(const ldld &a, const ldld &b)
{
	return (b.first - a.first) / (a.second - b.second);
}

void Insert(const ldld &l)
{
	if (Slen > 0 && S[Slen - 1].first <= l.first + eps) return;
	while (Slen > 0 && S[Slen - 1].first + S[Slen - 1].second + eps >= l.first + l.second) Slen--;
	while (Slen > 1) {
		ld x1 = Cross(S[Slen - 2], l);
		ld x2 = Cross(S[Slen - 1], l);
		if (x1 + eps >= x2) break;
		else Slen--;
	}
	S[Slen++] = l;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		seq[i].first = ldld(1.0l / a, ld(a - b) / ld(a * b));
		seq[i].second = i + 1;
	}
	sort(seq, seq + n, Less);
	for (int i = 0; i < n; i++)
		Insert(seq[i].first);
	for (int i = 0; i < Slen; i++)
		St.insert(S[i]);
	for (int i = 0; i < n; i++)
		if (St.find(seq[i].first) != St.end())
			res.push_back(seq[i].second);
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}