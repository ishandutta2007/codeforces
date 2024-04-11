#include <bits/stdc++.h>
using namespace std;

typedef pair <char, char> cc;

const int Maxl = 26;
const int Maxn = 100005;

int n;
char A[Maxn], B[Maxn];
vector <int> neigh[Maxl];
char col[Maxl];
vector <cc> res;

void Fill(int v, char c)
{
	if (col[v] != '?') return;
	col[v] = c;
	for (int i = 0; i < neigh[v].size(); i++)
		Fill(neigh[v][i], c);
}

int main()
{
	fill(col, col + Maxl, '?');
	scanf("%d", &n);
	scanf("%s", A);
	scanf("%s", B);
	for (int i = 0; i < n; i++) {
		int a = A[i] - 'a', b = B[i] - 'a';
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	for (int i = 0; i < Maxl; i++) if (col[i] == '?') 
		Fill(i, 'a' + i);
	else res.push_back(cc(col[i], 'a' + i));
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%c %c\n", res[i].first, res[i].second);
	return 0;
}