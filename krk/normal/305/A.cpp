#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 105;

int k, d[Maxn];
int a, b;
vector <int> res;

int main()
{
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &d[i]);
		if (d[i] == 0 || d[i] == 100) res.push_back(d[i]);
		else if (d[i] < 10) a = d[i];
		else if (d[i] % 10 == 0) b = d[i];
	}
	if (a && b) { res.push_back(a); res.push_back(b); }
	else for (int i = 0; i < k; i++)
			if (d[i] != 0 && d[i] != 100) { res.push_back(d[i]); break; }
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}