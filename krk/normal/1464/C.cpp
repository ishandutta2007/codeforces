#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 60;

int n;
ll T;
string s;
int tims[Maxn];
int has[Maxn];

int main()
{
	scanf("%d %I64d", &n, &T);
	cin >> s;
	reverse(s.begin(), s.end());
	int ind = s[0] - 'a';
	T -= 1ll << ll(ind);
	ind = s[1] - 'a';
	T += 1ll << ll(ind);
	if (T > 0) T = -T;
	for (int i = 2; i < s.length(); i++)
		tims[s[i] - 'a']++;
	for (int i = 0; i < Maxn; i++) if (tims[i]) {
		T += ll(tims[i]) * (1ll << ll(i));
		has[i + 1] += tims[i];
	}
	if (T < 0) { printf("No\n"); return 0; }
	for (int i = 0; i < Maxn; i++) {
		if (T & 1ll << ll(i))
			if (has[i] == 0) { printf("No\n"); return 0; }
			else has[i]--;
		if (i + 1 < Maxn)
			has[i + 1] += has[i] / 2;
	}
	printf("Yes\n");
    return 0;
}