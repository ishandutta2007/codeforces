#include <cstdio>
#include <vector>
using namespace std;

const int Maxm = 1005;

int n;
bool was[Maxm];
vector <int> a, b;

int main()
{
	int num;
	while (scanf("%d,", &num) == 1) {
		was[num]++;
	}
	for (int i = 0; i < Maxm; i++) if (was[i])
		if (!b.empty() && b.back() == i - 1) b.back() = i;
		else { a.push_back(i); b.push_back(i); }
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) printf("%d", a[i]);
		else printf("%d-%d", a[i], b[i]);
		printf("%s", i + 1 < a.size()? ",": "\n");
	}
	return 0;
}