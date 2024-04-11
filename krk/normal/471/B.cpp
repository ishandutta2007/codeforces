#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 2005;

int n;
vector <int> has[Maxn];
vector <int> cur;
vector <vector <int> > res;
bool taken[Maxn];
int fromhas[Maxn];

void Traverse(int lvl)
{
	if (lvl == Maxn) res.push_back(cur);
	else if (fromhas[lvl] >= has[lvl].size()) Traverse(lvl + 1);
	else {
		fromhas[lvl]++;
		for (int i = 0; i < has[lvl].size() && res.size() < 3; i++) if (!taken[has[lvl][i]]) {
			cur.push_back(has[lvl][i]); taken[has[lvl][i]] = true;
			Traverse(lvl);
			cur.pop_back(); taken[has[lvl][i]] = false;
		}
		fromhas[lvl]--;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		has[a].push_back(i);
	}
	Traverse(1);
	if (res.size() < 3) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 0; i < res.size(); i++)
			for (int j = 0; j < res[i].size(); j++)
				printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
	}
	return 0;
}