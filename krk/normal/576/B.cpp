#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 100005;

int n;
int p[Maxn];
bool tk[Maxn];
vector <vector <int> > S[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		vector <int> seq; seq.push_back(i); tk[i] = true;
		int num = p[i];
		while (i != num) {
			seq.push_back(num); tk[num] = true;
			num = p[num];
		}
		S[seq.size()].push_back(seq);
	}
	if (S[1].empty() && S[2].empty()) { printf("NO\n"); return 0; }
	if (!S[1].empty()) {
		printf("YES\n");
		vector <int> cur = S[1].back(); S[1].pop_back();
		for (int i = 1; i < Maxn; i++)
			for (int j = 0; j < S[i].size(); j++)
				for (int l = 0; l < S[i][j].size(); l++)
					printf("%d %d\n", cur[0], S[i][j][l]);
	} else {
		bool ok = true;
		for (int i = 3; i < Maxn; i += 2)
			if (!S[i].empty()) ok = false;
		if (!ok) { printf("NO\n"); return 0; }
		printf("YES\n");
		vector <int> cur = S[2].back(); S[2].pop_back();
		printf("%d %d\n", cur[0], cur[1]);
		for (int i = 2; i < Maxn; i++)
			for (int j = 0; j < S[i].size(); j++)
				for (int l = 0; l < S[i][j].size(); l++)
					printf("%d %d\n", cur[l % 2], S[i][j][l]);
	}
	return 0;
}