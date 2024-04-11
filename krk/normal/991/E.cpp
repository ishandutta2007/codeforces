#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int Maxm = 20;
const int Maxd = 10;

ll C[Maxm][Maxm];
ll n;
int has[Maxd];
int tk[Maxd];
ll res;

void Gen(int lvl, int tot)
{
	if (lvl >= Maxd) {
		ll ways = C[tot - 1][tk[0]];
		tot -= tk[0];
		for (int i = 1; i < Maxd; i++) {
			ways *= C[tot][tk[i]];
			tot -= tk[i];
		}
		res += ways;
	} else if (has[lvl] == 0) {
		tk[lvl] = 0; Gen(lvl + 1, tot);
	} else for (tk[lvl] = 1; tk[lvl] <= has[lvl]; tk[lvl]++)
			Gen(lvl + 1, tot + tk[lvl]);
}

int main()
{
	for (int i = 0; i < Maxm; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	cin >> n;
	while (n) {
		has[n % 10]++;
		n /= 10;
	}
	Gen(0, 0);
	cout << res << endl;
	return 0;
}