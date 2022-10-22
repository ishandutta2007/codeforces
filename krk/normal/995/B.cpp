#include <bits/stdc++.h>
using namespace std;

const int Maxm = 105;

int n;
vector <int> seq[Maxm];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		int a; scanf("%d", &a);
		seq[a].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (seq[i][1] < seq[j][0] || seq[j][1] < seq[i][0]) res += 0;
			else if (seq[i][0] < seq[j][0] && seq[j][1] < seq[i][1] ||
					 seq[j][0] < seq[i][0] && seq[i][1] < seq[j][1]) res += 2;
			else res++;
	printf("%d\n", res);
	return 0;
}