#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int u[Maxn];
int s[Maxn];
vector <int> seq[Maxn];
ll delt[Maxn];
ll sum[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			seq[i].clear();
			delt[i] = 0;
		}
		for (int i = 1; i <= n; i++)
			scanf("%d", &u[i]);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &s[i]);
			delt[1] += s[i];
			seq[u[i]].push_back(s[i]);
		}
		for (int i = 1; i <= n; i++) {
			sort(seq[i].rbegin(), seq[i].rend());
			sum[seq[i].size()] = 0;
			for (int j = int(seq[i].size()) - 1; j >= 0; j--)
				sum[j] = sum[j + 1] + seq[i][j];
			for (int j = 1; j <= seq[i].size(); j++) {
				ll val = sum[seq[i].size() / j * j];
				delt[j] -= val;
				delt[j + 1] += val;
			}
			delt[seq[i].size() + 1] -= sum[0];
		}
		ll cur = 0;
		for (int i = 1; i <= n; i++) {
			cur += delt[i];
			printf("%I64d%c", cur, i + 1 <= n? ' ': '\n');
		}
	}
    return 0;
}