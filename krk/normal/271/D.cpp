#include <cstdio>
#include <iostream>
#include <set>
#include <string>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int a = 37;
const int Maxl = 26;

string s;
int cost[Maxl];
int k;
set <ii> S;

int main()
{
	cin >> s;
	for (int i = 0; i < Maxl; i++) {
		char c; scanf(" %c", &c);
		cost[i] = c == '0';
	}
	scanf("%d", &k);
	for (int i = 0; i < s.length(); i++) {
		int has = 0, hsh1 = 0, hsh2 = 0;
		for (int j = i; has + cost[s[j] - 'a'] <= k && j < s.length(); j++) {
			has += cost[s[j] - 'a'];
			hsh1 = (ll(hsh1) * ll(a) + ll(s[j] - 'a' + 1)) % ll(mod1);
			hsh2 = (ll(hsh2) * ll(a) + ll(s[j] - 'a' + 1)) % ll(mod2);
			S.insert(ii(hsh1, hsh2));
		}
	}
	printf("%d\n", S.size());
	return 0;
}