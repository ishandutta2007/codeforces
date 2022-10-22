#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int lim = 3;
const int Maxn = 1005;

int n;
int a[Maxn];
vector <int> l, r;
bool found;

int fromLeft()
{
	for (int i = 0; i < n; i++)
		if (a[i] != i + 1) return i;
	return -1;
}

int fromRight()
{
	for (int i = n - 1; i >= 0; i--)
		if (a[i] != i + 1) return i;
	return -1;
}

int getPos(int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x) return i;
}

void Print()
{
	printf("%d\n", l.size());
	for (int i = l.size() - 1; i >= 0; i--)
		printf("%d %d\n", l[i], r[i]);
}

void Gen(int lvl)
{
	if (fromLeft() == -1) { Print(); found = true; }
	if (found || lvl == lim) return;
	int li = fromLeft();
	int pos = getPos(li + 1);
	reverse(a + li, a + pos + 1);
	l.push_back(li + 1); r.push_back(pos + 1);
	Gen(lvl + 1);
	if (found) return;
	reverse(a + li, a + pos + 1);
	l.pop_back(); r.pop_back();
	int ri = fromRight();
	pos = getPos(ri + 1);
	reverse(a + pos, a + ri + 1);
	l.push_back(pos + 1); r.push_back(ri + 1);
	Gen(lvl + 1);
	reverse(a + pos, a + ri + 1);
	l.pop_back(); r.pop_back();
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	Gen(0);
	return 0;
}