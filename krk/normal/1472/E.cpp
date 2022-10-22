#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 200005;

int T;
int n;
vector <iii> seq;
int res[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		seq.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int h, w; scanf("%d %d", &h, &w);
			seq.push_back(iii(ii(h, w), i));
			seq.push_back(iii(ii(w, h), i));
			res[i] = -2;
		}
		sort(seq.begin(), seq.end());
		ii mn = ii(2000000000, -2);
		for (int i = 0, j; i < seq.size(); i = j) {
			j = i;
			while (j < seq.size() && seq[i].first.first == seq[j].first.first) {
				if (mn.first < seq[j].first.second)
					res[seq[j].second] = mn.second;
				j++;
			}
			for (int l = i; l < j; l++)
				mn = min(mn, ii(seq[l].first.second, seq[l].second));
		}
		for (int i = 0; i < n; i++)
			printf("%d%c", res[i] + 1, i + 1 < n? ' ': '\n');
	}
    return 0;
}