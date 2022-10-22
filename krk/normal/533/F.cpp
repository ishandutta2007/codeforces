#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;
const int Maxl = 26;
const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 116853533;
const int arg2 = 124047823;

int slen, tlen;
char S[Maxn], T[Maxn];
int Barg1, Barg2;
int pos[Maxl];
ii myH[Maxl], curH[Maxl];
vector <int> res;

int toPower(int a, int p, int mod)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

void Add(ii &H, int val)
{
	H.first = (ll(H.first) * arg1 + val) % mod1;
	H.second = (ll(H.second) * arg2 + val) % mod2;
}

void Rem(ii &H, int val)
{
	H.first = (H.first - ll(val) * Barg1 % mod1 + mod1) % mod1;
	H.second = (H.second - ll(val) * Barg2 % mod2 + mod2) % mod2;
}

bool Check(int st)
{
	for (int i = 0; i < Maxl; i++) if (pos[i] != -1) {
		int ch = S[st + pos[i]] - 'a';
		if (!(myH[i] == curH[ch] && myH[ch] == curH[i])) return false;
	}
	return true;
}

int main()
{
	scanf("%d %d", &slen, &tlen);
	scanf("%s", S); scanf("%s", T);
	Barg1 = toPower(arg1, tlen - 1, mod1);
	Barg2 = toPower(arg2, tlen - 1, mod2);
	fill(pos, pos + Maxl, -1);
	for (int i = 0; i < tlen; i++) {
		pos[T[i] - 'a'] = i;
		for (int j = 0; j < Maxl; j++)
			Add(myH[j], 1 + (T[i] - 'a' == j));
	}
	for (int i = 0; i < tlen - 1; i++)
		for (int j = 0; j < Maxl; j++)
			Add(curH[j], 1 + (S[i] - 'a' == j));
	for (int i = tlen - 1; i < slen; i++) {
		if (i >= tlen)
			for (int j = 0; j < Maxl; j++)
				Rem(curH[j], 1 + (S[i - tlen] - 'a' == j));
		for (int j = 0; j < Maxl; j++)
			Add(curH[j], 1 + (S[i] - 'a' == j));
		if (Check(i - tlen + 1)) res.push_back(i - tlen + 2);
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}