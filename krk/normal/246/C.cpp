#include <cstdio>
#include <set>
#include <vector>
using namespace std;

const int Maxn = 55;

int n, k;
int a[Maxn];
set <int> was[Maxn];
vector <int> seq;

void Gen(int lvl, int sum)
{
	if (was[lvl].find(sum) != was[lvl].end())
		return;
	was[lvl].insert(sum);
	if (lvl == n) {
		if (!seq.empty()) {
			printf("%d", seq.size());
			for (int i = 0; i < seq.size(); i++)
				printf(" %d", seq[i]);
			printf("\n");
			k--;
		}
	} else {
		Gen(lvl + 1, sum);
		if (!k) return;
		seq.push_back(a[lvl]);
		Gen(lvl + 1, sum + a[lvl]);
		seq.pop_back();
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) 
		scanf("%d", &a[i]);
	Gen(0, 0);
	return 0;
}