#include <cstdio>
#include <vector>
using namespace std;

int n;
vector <int> V;

int main()
{
	scanf("%d", &n);
	if (n == 1) V.push_back(1);
	else if (n == 2) V.push_back(1);
	else if (n == 3) { V.push_back(1); V.push_back(3); }
	else {
		int a = (n + 2) / 2, b = 1;
		bool froma = true;
		for (int i = 0; i < n; i++) {
			if (froma) V.push_back(a++);
			else V.push_back(b++);
			froma = !froma;
		}
	}
	printf("%d\n", V.size());
	for (int i = 0; i < V.size(); i++)
		printf("%d%c", V[i], i + 1 < V.size()? ' ': '\n');
	return 0;
}