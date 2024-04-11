#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int n, k;
vector <ii> V;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < 256; i++)
		V.push_back(ii(i, i));
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		ii p;
		int ind;
		for (int j = 0; j < V.size(); j++)
			if (V[j].first <= a && a <= V[j].second) {
				p = V[j]; ind = j; V.erase(V.begin() + j);
				break;
			}
		while (ind > 0) {
			ind--;
			if (p.second - V[ind].first + 1 <= k) {
				p.first = V[ind].first; V.erase(V.begin() + ind);
			} else { ind++; break; }
		}
		V.insert(V.begin() + ind, p);
		printf("%d%c", p.first, i + 1 < n? ' ': '\n');
	}
	return 0;
}