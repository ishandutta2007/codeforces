#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int has[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(has, has + Maxn, 0);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			has[a]++;
		}
		vector <int> seq;
		for (int i = 0; i < Maxn && has[i] > 0; i++) {
			seq.push_back(i);
			has[i]--;
		}
		for (int i = 0; i < Maxn; i++)
			while (has[i] > 0) {
				seq.push_back(i);
				has[i]--;
			}
		for (int i = 0; i < seq.size(); i++)
			printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
	}
    return 0;
}