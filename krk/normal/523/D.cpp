#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

const int Maxn = 500005;

int n, k;
int S[Maxn], M[Maxn];
multiset <ll> St;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &S[i], &M[i]);
		while (!St.empty() && *St.begin() <= S[i]) St.erase(St.begin());
		ll cur = S[i];
		if (St.size() == k) { cur = *St.begin(); St.erase(St.begin()); }
		printf("%I64d\n", cur + M[i]);
		St.insert(cur + M[i]);
	}
	return 0;
}