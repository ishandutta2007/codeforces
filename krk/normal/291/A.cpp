#include <cstdio>
#include <map>
using namespace std;

int n;
map <int, int> M;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		int id; scanf("%d", &id);
		if (id) M[id]++;
	}
	map <int, int>::iterator it;
	for (it = M.begin(); it != M.end(); it++)
		if (it->second > 2) break;
		else if (it->second == 2) res++;
	printf("%d\n", it == M.end()? res: -1);
	return 0;
}