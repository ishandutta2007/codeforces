#include <cstdio>
#include <set>
#include <map>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int w, h, n;
set <ii> V, H;
map <int, int> myV, myH;

void Update(map <int, int> &M, set <ii> &S, int num)
{
	map <int, int>::iterator it = M.upper_bound(num); it--;
	S.erase(ii(it->second, it->first));
	int m = it->second;
	it->second = num - it->first;
	S.insert(ii(it->second, it->first));
	M[num] = it->first + m - num; S.insert(ii(it->first + m - num, num));
}

int main()
{
	scanf("%d %d %d", &w, &h, &n);
	myV[0] = w; V.insert(ii(w, 0));
	myH[0] = h; H.insert(ii(h, 0));
	while (n--) {
		char ch;
		int num;
		scanf(" %c %d", &ch, &num);
		if (ch == 'H') Update(myH, H, num);
		else Update(myV, V, num);
		printf("%I64d\n", ll(V.rbegin()->first) * H.rbegin()->first);
	}
	return 0;
}