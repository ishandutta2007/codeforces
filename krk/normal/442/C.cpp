#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxm = 1000005;

int n;
set <ii> S;
vector <int> V[Maxm];
int nil;
ll res;

int Next(set <ii>::iterator it)
{
	it++;
	if (it == S.end()) return 0;
	return it->second - nil;
}

int Prev(set <ii>::iterator it)
{
	if (it == S.begin()) return 0;
	it--; return it->second - nil;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		S.insert(ii(i, a));
		V[a].push_back(i);
	}
	for (int i = 1; i < Maxm; i++)
		for (int j = 0; j < V[i].size() && S.size() > 2; j++) {
			res += ll(S.size() - 2) * (i - nil);
			nil = i;
			set <ii>::iterator it = S.find(ii(V[i][j], i));
			res += min(Next(it), Prev(it));
			S.erase(it);
		}
	printf("%I64d\n", res);
	return 0;
}