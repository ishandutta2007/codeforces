#include <cstdio>
#include <map>
using namespace std;

const int Maxn = 100005;

int n, m, k;
map <int, int> K;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		int typ; scanf("%d", &typ);
		K[typ]++;
	}
	for (int i = 0; i < m; i++) {
		int typ; scanf("%d", &typ);
		K[typ]--;
	}
	int car = 0;
	map <int, int>::reverse_iterator it;
	for (it = K.rbegin(); it != K.rend(); it++) {
		it->second += car; car = 0;
		if (it->second > 0) break;
		car = it->second;
	}
	printf("%s\n", it != K.rend()? "YES": "NO");
	return 0;
}