#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

map <ll, ll> M[2];
int n, k;
ll a[Maxn];
ll res;

ll Get(map <ll, ll> &M, ll val)
{
	map <ll, ll>::iterator it = M.find(val);
	return it == M.end()? 0: it->second;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = n - 1; i >= 0; i--) {
		res += Get(M[1], a[i] * k);
		M[1][a[i]] += Get(M[0], a[i] * k);
		M[0][a[i]]++;
	}
	printf("%I64d\n", res);
	return 0;
}