#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <char, char> cc;

const int Maxn = 200005;

int n, m;
map <ii, char> M;
int samedge;
map <cc, int> my[Maxn];
int sammy;

void Add(int a, int b, char ch)
{
	M[ii(a, b)] = ch;
	auto it = M.find(ii(b, a));
	if (it == M.end()) return;
	if (it->second == ch) samedge++;
	if (my[b][cc(ch, it->second)]++ == 0) sammy++;
	if (my[a][cc(it->second, ch)]++ == 0) sammy++;
}

void Rem(int a, int b)
{
	char ch = M[ii(a, b)];
	M.erase(ii(a, b));
	auto it = M.find(ii(b, a));
	if (it == M.end()) return;
	if (it->second == ch) samedge--;
	if (--my[b][cc(ch, it->second)] == 0) sammy--;
	if (--my[a][cc(it->second, ch)] == 0) sammy--;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		char typ, ch;
		int a, b;
		scanf(" %c", &typ);
		if (typ == '+') {
			scanf("%d %d %c", &a, &b, &ch);
			Add(a, b, ch);
		} else if (typ == '-') {
			scanf("%d %d", &a, &b);
			Rem(a, b);
		} else {
			scanf("%d", &a);
			if (a % 2 != 0 && sammy > 0 ||
				a % 2 == 0 && samedge > 0)
				printf("YES\n");
			else printf("NO\n");
		}
	}
    return 0;
}