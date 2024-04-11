#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int a = 1000000001;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int Maxn = 100005;
const int Maxm = 20;

int n;
int S[Maxn];
map <int, vector <int> > inpos;
int A1[Maxn], A2[Maxn];
int H1[Maxn][Maxm], H2[Maxn][Maxm];
vector <ii> rep;
int res;

int getHash(int p, int l, int H[][Maxm], int A[Maxn], int mod)
{
	int j = 0;
	while (1 << j <= l) j++;
	j--;
	int res = 0;
	for (; j >= 0; j--)
		if (1 << j <= l) {
			res = ll(res) * ll(A[j + 1]) + ll(H[p][j]) % ll(mod);
			p += 1 << j; l -= 1 << j;  
		}
	return res;
}

bool Equal(int a, int b)
{
	if (b + b - a > n) return false;
	return getHash(a, b - a, H1, A1, mod1) == getHash(b, b - a, H1, A1, mod1) &&
			getHash(a, b - a, H2, A2, mod2) == getHash(b, b - a, H2, A2, mod2);
}

int main()
{
	A1[0] = A2[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		A1[i] = ll(A1[i - 1]) * ll(a) % ll(mod1);
		A2[i] = ll(A2[i - 1]) * ll(a) % ll(mod2);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &H1[i][0]); H2[i][0] = H1[i][0]; inpos[H1[i][0]].push_back(i); }
	for (int j = 1; 1 << j - 1 <= n; j++)
		for (int i = 0; i + (1 << j - 1) <= n; i++) {
			H1[i][j] = (ll(H1[i][j - 1]) * ll(A1[j]) + ll(H1[i + (1 << j - 1)][j - 1])) % ll(mod1);
			H2[i][j] = (ll(H2[i][j - 1]) * ll(A2[j]) + ll(H2[i + (1 << j - 1)][j - 1])) % ll(mod2);
		}
	for (int i = 0; i < Maxn; i++) {
		map <int, vector <int> >::iterator it = inpos.find(H1[i][0]);
		for (int j = 0; j < it->second.size(); j++)
			if (i < it->second[j] && Equal(i, it->second[j])) rep.push_back(ii(it->second[j] - i, i));
	}
	sort(rep.begin(), rep.end());
	for (int i = 0; i < rep.size(); i++)
		if (res <= rep[i].second) res = rep[i].second + rep[i].first;
	printf("%d\n", n - res);
	for (int i = res; i < n; i++)
		printf("%d%c", H1[i][0], i + 1 < n? ' ': '\n');
	return 0;
}