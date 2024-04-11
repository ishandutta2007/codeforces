#include <cstdio>
#include <vector>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

int lim = 100000;
ll x, k;
vector <ll> divs;
vector <vector <int> > ndivs;
bool wasp;

void Print(int lvl, int wh)
{
	if (wh == 0) {
		if (lim) {
			if (wasp) printf(" ");
			wasp = true;
			printf("%I64d", divs[wh]);
			lim--;
		}
		return;
	}
	if (lvl == k) {
		if (wasp) printf(" ");
		wasp = true;
		printf("%I64d", divs[wh]);
		lim--;
	} else for (int i = 0; i < ndivs[wh].size() && lim; i++)
				Print(lvl + 1, ndivs[wh][i]);
}

int main()
{
	scanf("%lld %lld", &x, &k);
	if (x == 1) printf("1\n");
	else if (k > lim)
		while (lim--) printf("1%c", lim? ' ': '\n');
	else {
		for (ll i = 1; i * i <= x; i++)
			if (x % i == 0) {
				divs.push_back(i);
				if (i * i != x) divs.push_back(x / i);
			}
		sort(divs.begin(), divs.end());
		ndivs.resize(divs.size());
		for (int i = 0; i < divs.size(); i++)
			for (int j = i; j < divs.size(); j++)
				if (divs[j] % divs[i] == 0) ndivs[j].push_back(i);
		Print(0, divs.size() - 1); printf("\n");
	}
	return 0;
}