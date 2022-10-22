#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 101;
const int Inf = 1000000000;
const int Maxm = 5000005;
 
int l, r, P;
bool prime[Maxn];
int seq[Maxm], slen;
int cnt[Maxm];
bool yes[Maxm];
vector <int> pr;
int res;
 
void Solve(int my, int from, int tims)
{
	seq[slen++] = my;
	for (int i = from; i < pr.size() && my <= Inf / pr[i]; i++)
		Solve(my * pr[i], i, tims + 1);
}
 
int main()
{
	fill(prime + 2, prime + Maxn, true);
	for (int i = 2; i < Maxn; i++) if (prime[i]) {
		pr.push_back(i);
		for (int j = i + i; j < Maxn; j += i)
			prime[j] = false;
	}
	scanf("%d %d %d", &l, &r, &P);
	Solve(1, 0, 0);
	fill(cnt, cnt + slen, P + 1);
	sort(seq, seq + slen);
	cnt[0] = 0;
	for (int j = 2; j < P; j++) {
		int p = 0;
		for (int i = 0; i < slen; i++) if (seq[i] % j == 0) {
			while (p < slen && seq[i] / j > seq[p]) p++;
			if (p < slen && seq[i] / j == seq[p]) {
				int cand = cnt[p] + 1;
				if (cand < cnt[i]) cnt[i] = cand;
				if (cnt[i] + j <= P) yes[i] = true;
			}
		}
	}
	for (int i = 0; i < slen; i++)
		if (l <= seq[i] && seq[i] <= r && yes[i])
			res++;
	printf("%d\n", res);
    return 0;
}