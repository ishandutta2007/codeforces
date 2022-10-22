#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int h[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &h[i]);
		sort(h, h + n);
		int mn = h[1] - h[0], best = 0;
		vector <int> seq;
		for (int i = 1; i + 1 < n; i++)
			if (h[i + 1] - h[i] < mn) {
				mn = h[i + 1] - h[i];
				best = i;
			}
		seq.push_back(h[best]);
		for (int i = best + 2; i < n; i++)
			seq.push_back(h[i]);
		for (int i = 0; i < best; i++)
			seq.push_back(h[i]);
		seq.push_back(h[best + 1]);
		for (int i = 0; i < seq.size(); i++)
			printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
	}
    return 0;
}