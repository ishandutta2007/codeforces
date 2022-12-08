#include <stdio.h>
#include <set>
using namespace std;

int main()
{
	set<pair<int, int> > chk;
	int n; scanf ("%d", &n);
	for (int k = 0; k <= n; k++){
		for (int i = k * 2; i <= k * 2 + 2; i++){
			for (int j = k * 2; j <= k * 2 + 2; j++){
				chk.insert({ i,j });
			}
		}
		chk.erase({ k * 2 + 1,k * 2 + 1 });
	}

	printf ("%d\n", chk.size());
	for (auto& p : chk) printf ("%d %d\n", p.first, p.second);
	return 0;
}