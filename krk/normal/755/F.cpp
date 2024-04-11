#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 1000005;
const int Maxm = 10000;

int n, k;
int p[Maxn];
bool tk[Maxn];
int freq[Maxn];
vector <int> seq;
int sum[Maxn];
map <int, bool> has[Maxm];

bool Solve(int ind, int val)
{
	if (val == 0) return true;
	if (ind < 0) return false;
	if (sum[ind] < val) return false;
	if (sum[ind] == val) return true;
	map <int, bool>::iterator it = has[ind].find(val);
	if (it == has[ind].end()) {
		bool res = false;
		for (int i = 0, cur = 0; i <= freq[seq[ind]] && cur <= val; i++, cur += seq[ind])
			if (Solve(ind - 1, val - cur)) { res = true; break; }
		has[ind][val] = res; return res;
	}
	return it->second;
}

int main() 
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) if (!tk[i]) {
		int cur = i;
		int cnt = 0;
		while (!tk[cur]) { tk[cur] = true; cnt++; cur = p[cur]; }
		seq.push_back(cnt); freq[cnt]++; 
	}
	sort(seq.begin(), seq.end()); seq.erase(unique(seq.begin(), seq.end()), seq.end());
	sum[0] = freq[seq[0]] * seq[0];
	for (int i = 1; i < seq.size(); i++)
		sum[i] = sum[i - 1] + freq[seq[i]] * seq[i];
	int fin = k > n - k? n - k: k;
	if (Solve(int(seq.size()) - 1, fin)) printf("%d ", k);
	else printf("%d ", k + 1);
	int res = 0;
	int cnt = 0;
	for (int i = 0; i < seq.size(); i++)
		for (int j = 0; j < freq[seq[i]]; j++) {
			int tk = min(seq[i] / 2, k); res += 2 * tk;
			k -= tk; if (seq[i] % 2 == 1) cnt++;
		}
	int tk = min(cnt, k);
	res += tk;
	printf("%d\n", res);
    return 0;
}