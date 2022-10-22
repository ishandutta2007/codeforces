#include <cstdio>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int X1, X2;
int k[Maxn], b[Maxn];
map <ll, vector <int> > M;

int main()
{
	scanf("%d", &n);
	scanf("%d %d", &X1, &X2);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &k[i], &b[i]);
		M[ll(k[i]) * X1 + b[i]].push_back(i);
	}
	ll mx = -1000000000000000000ll;
	for (map <ll, vector <int> >::iterator it = M.begin(); it != M.end(); it++) {
		for (int i = 0; i < it->second.size(); i++) {
			int ind = it->second[i];
			ll val = ll(k[ind]) * X2 + b[ind];
			if (val < mx) { printf("YES\n"); return 0; }
		}
		for (int i = 0; i < it->second.size(); i++) {
			int ind = it->second[i];
			mx = max(mx, ll(k[ind]) * X2 + b[ind]);
		}
	}
	printf("NO\n");
	return 0;
}