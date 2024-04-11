#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n, d;
ll x;
int a[Maxn], b[Maxn];
int c[Maxn];
vector <int> ind;
set <ii> S;

ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
	int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main()
{
	scanf("%d %d %I64d", &n, &d, &x);
	initAB();
	if (d <= 500) {
		for (int i = 0; i < n; i++)
			if (b[i]) ind.push_back(i);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < ind.size() && ind[j] <= i; j++)
				c[i] = max(c[i], a[i - ind[j]]);
	} else for (int i = 0; i < n; i++) {
			S.insert(ii(a[i], i));
			for (set <ii>::reverse_iterator it = S.rbegin(); it != S.rend(); it++)
				if (b[i - it->second]) { c[i] = it->first; break; }
		}
	for (int i = 0; i < n; i++)
		printf("%d\n", c[i]);
	return 0;
}