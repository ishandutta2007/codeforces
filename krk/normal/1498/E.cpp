#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 505;

int n;
int k[Maxn];
vector <iii> V;

bool Solve(int a, int b)
{
	printf("? %d %d\n", a, b); fflush(stdout);
	string s; cin >> s;
	return s == "Yes";
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &k[i]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (k[i] >= k[j]) V.push_back(iii(k[i] - k[j], ii(i, j)));
			else V.push_back(iii(k[j] - k[i], ii(j, i)));
	sort(V.rbegin(), V.rend());
	for (int i = 0; i < V.size(); i++)
		if (Solve(V[i].second.first, V[i].second.second)) {
			printf("! %d %d\n", V[i].second.first, V[i].second.second);
			fflush(stdout);
			return 0;
		}
	printf("! 0 0\n");
	fflush(stdout);
    return 0;
}