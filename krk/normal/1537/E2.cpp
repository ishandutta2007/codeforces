#include <bits/stdc++.h>
using namespace std;
 
typedef pair <int, int> ii;
 
const int Maxn = 2000005;
char s[Maxn];
int slen;
int rnk[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];
 
bool Less(const int &a, const int &b) { return s[a] < s[b]; }
 
void buildSA()
{
	for (int i = 0; i < slen; i++)
		cur[i] = i;
	sort(cur, cur + slen, Less);
	for (int i = 0; i < slen; i++) {
		dif1[i] = i == 0 || s[cur[i - 1]] != s[cur[i]];
		dif2[i] = false;
	}
	for (int h = 1; h < slen; h <<= 1) {
		int buck = 0;
		for (int i = 0, j; i < slen; i = j) {
			j = i + 1;
			while (j < slen && !dif1[j]) j++;
			nxt[i] = j;
			buck++;
		}
		if (buck == slen) break;
		for (int i = 0; i < slen; i = nxt[i]) {
			cnt[i] = 0;
			for (int j = i; j < nxt[i]; j++)
				rnk[cur[j]] = i;
		}
		cnt[rnk[slen - h]]++; dif2[rnk[slen - h]] = true;
		for (int i = 0; i < slen; i = nxt[i]) {
			for (int j = i; j < nxt[i]; j++) {
				int s = cur[j] - h;
				if (s >= 0) {
					int head = rnk[s];
					rnk[s] = head + cnt[head]++;
					dif2[rnk[s]] = true;
				}
			}
			for (int j = i; j < nxt[i]; j++) {
				int s = cur[j] - h;
				if (s >= 0 && dif2[rnk[s]])
					for (int k = rnk[s] + 1; !dif1[k] && dif2[k]; k++) dif2[k] = false;
			}
		}
		for (int i = 0; i < slen; i++) {
			cur[rnk[i]] = i;
			dif1[i] |= dif2[i];
		}
	}
}
 
 
int n, k;
char tmp[Maxn];
 
int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	slen = n;
	while (slen < 2 * n) {
		s[slen] = s[slen % n];
		slen++;
	}
	buildSA();
	for (int i = 0; i < slen; i++)
		rnk[cur[i]] = i;
	for (int i = 1; i < n; i++) if (rnk[i] > rnk[0]) {
		n = i; break;
	}
	for (int i = 0; i < k; i++)
		tmp[i] = s[i % n];
	tmp[k] = '\0';
	printf("%s\n", tmp);
    return 0;
}