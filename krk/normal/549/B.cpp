#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 105;

int n;
char neigh[Maxn][Maxn];
int a[Maxn];
vector <int> seq;

bool getZero(int &val)
{
	for (int i = 0; i < n; i++)
		if (a[i] == 0) { val = i; return true; }
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", neigh[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int i;
	while (getZero(i)) {
		for (int j = 0; j < n; j++)
			if (neigh[i][j] == '1') a[j]--;
		seq.push_back(i);
	}
	printf("%d\n", seq.size());
	for (int i = 0; i < seq.size(); i++)
		printf("%d%c", seq[i] + 1, i + 1 < seq.size()? ' ': '\n');
	return 0;
}