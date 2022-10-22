#include <cstdio>
#include <vector>
using namespace std;

int n;
vector <int> V;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int my = 1;
		while (!V.empty() && V.back() == my) { my++; V.pop_back(); }
		V.push_back(my);
	}
	for (int i = 0; i < V.size(); i++)
		printf("%d%c", V[i], i + 1 < V.size()? ' ': '\n');
	return 0;
}