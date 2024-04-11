#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxl = 26;

int T;
int n, k;
char str[Maxn];
int cnt[Maxl];

bool checkCnt()
{
	int all = 0;
	for (int i = 0; i < Maxl; i++)
		if (cnt[i] > 0)
			all += ((cnt[i] - 1) / k + 1) * k;
	return all <= n;
}

void updateCnt(int ind)
{
	int all = 0;
	for (int i = 0; i < Maxl; i++)
		if (cnt[i] > 0) {
			cnt[i] = ((cnt[i] - 1) / k + 1) * k;
			all += cnt[i];
		}
	cnt[ind] += n - all;
}

bool Check(int len)
{
	fill(cnt, cnt + Maxl, 0);
	for (int i = 0; i < len; i++)
		cnt[str[i] - 'a']++;
	if (!checkCnt()) return false;
	updateCnt(Maxl - 1);
	for (int i = 0; i < len; i++)
		cnt[str[i] - 'a']--;
	int pnt = Maxl - 1;
	for (int i = len; i < n; i++) {
		while (cnt[pnt] == 0) pnt--;
		if (str[i] < 'a' + pnt) return true;
		if (str[i] > 'a' + pnt) return false;
		cnt[pnt]--;
	}
	return true;
}

void Solve(int len)
{
	if (len >= n) return;
	fill(cnt, cnt + Maxl, 0);
	for (int i = 0; i < len; i++)
		cnt[str[i] - 'a']++;
	while (true) {
		str[len]++;
		cnt[str[len] - 'a']++;
		if (checkCnt()) break;
		cnt[str[len] - 'a']--;
	}
	updateCnt(0);
	for (int i = 0; i <= len; i++)
		cnt[str[i] - 'a']--;
	int pnt = 0;
	for (int i = len + 1; i < n; i++) {
		while (cnt[pnt] == 0) pnt++;
		str[i] = 'a' + pnt;
		cnt[pnt]--;
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		scanf("%s", str);
		if (n % k) { printf("-1\n"); continue; }
		int l = 0, r = n;
		while (l <= r) {
			int m = l + r >> 1;
			if (Check(m)) l = m + 1;
			else r = m - 1;
		}
		if (r < 0) { printf("-1\n"); continue; }
		Solve(r);
		printf("%s\n", str); 
	}
    return 0;
}