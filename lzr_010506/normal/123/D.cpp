#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
const int N = 100010;
int len, n;
char ch[N];
namespace lzr
{
	void induced_sort(const int n, const int m, const int *S, int *SA, const bool *type, const int *buc, int *lbuc, int *sbuc)
	{
		int now;
		for(int i = 1; i <= m; i ++) sbuc[i] = buc[i] - 1;
		for(int i = 0; i <= n; i ++)
			if(SA[i] > 0 && !type[now = SA[i] - 1])
				SA[lbuc[S[now]] ++] = now;
		for(int i = n; i >= 0; i --)
			if(SA[i] > 0 &&  type[now = SA[i] - 1])
				SA[sbuc[S[now]] --] = now;
	}
	void SAIS(int n, const int m, const int* const S, int *SA)
	{
		n --;
		bool type[n + 1];
		int buc[m + 1], lbuc[m + 1], sbuc[m + 1], lms[n + 1], lab [n + 1];
		memset(buc, 0, sizeof(buc));
		memset(lbuc, 0, sizeof(lbuc));
        memset(sbuc, 0, sizeof(sbuc));
		for(int i = n; i >= 0; i --)
		{
			type[i] = i == n || (S[i] < S[i + 1]) || (S[i] == S[i + 1] && type[i + 1]);
			buc[S[i]] ++;
		}
		lbuc[0] = sbuc[0] = 0;
		for(int i = 1; i <= m; i ++) buc[i] += buc[i - 1], lbuc[i] = buc[i - 1], sbuc[i] = buc[i] - 1;
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			(type[i] && !type[i - 1]) ? lms[cnt ++] = i : 0;
		memset(SA, -1, (n + 1) << 2);
		for(int i = 0; i != cnt; i ++)
			SA[sbuc[S[lms[i]]] --] = lms[i];
		induced_sort(n, m, S, SA, type, buc, lbuc, sbuc);
		int *len = new int [n + 1];
		lms[cnt] = n + 1;
		for(int i = 0; i != cnt; i ++)
			len[lms[i]] = lms[i + 1] - lms[i] + 1;
		int m0 = 0;
		memset(lab, -1, (n + 1) << 2);
		for(int i = 1, p = -1, q = -1; i <= n; i ++)
			if((q = SA[i]) > 0 && type[q] && !type[q - 1])
			{
				if(p == -1 || len[p] != len[q] || memcmp(S + p, S + q, len[p] << 2)) m0 ++;
				lab[q] = m0;
				p = q;
			}
		lab[n] = 0;
		int *S1 = new int [cnt];
		int *SA1 = new int [cnt + 1];
		for(int i = 0, pos = 0; i <= n; i ++)
			(lab[i] >= 0) ? S1[pos ++] = lab[i] : 0;
		if(m0 + 1 == cnt)
			for(int i = 0; i != cnt; i ++)
				SA1[S1[i]] = i;
		else SAIS(cnt, m0, S1, SA1);
		//puts("wtf??");
		lbuc[0] = sbuc[0] = 0;
		for(int i = 1; i <= m; i ++) lbuc[i] = buc[i - 1], sbuc[i] = buc[i] - 1;
		memset(SA, -1, (n + 1) << 2);
		for(int i = cnt; i --; ) SA[sbuc[S[lms[SA1[i]]]] --] = lms[SA1[i]];
		//puts("wtf??");
		induced_sort(n, m, S, SA, type, buc, lbuc, sbuc);
		//delete []SA;
		//delete []type;
	}
};
using namespace lzr;
inline ll f(int x)
{
    return (ll)x * (x + 1) / 2;
}
int sa[N], a[N], rk[N], lcp[N];
int main()
{
	scanf("%s", ch);
	n = strlen(ch);
	a[n] = 0;
	rep(i, 0, n - 1)
		a[i] = ch[i] - 'a' + 1;
	SAIS(n + 1, 256, a, sa);
	//puts("Fk");
	for(int i = 0; i <= n; i ++)
		rk[sa[i]] = i;
    int k = 0, x, y;
	for(int i = 0; i < n; i ++)
	{
		if(k != 0) k --;
		else k = 0;
		x = sa[rk[i]];
		y = sa[rk[i] - 1];
		while(ch[x + k] == ch[y + k]) k ++;
		lcp[rk[i]] = k;
	}
	int h = 0;

	//build(ch, n);
	ll ans = 0;
	vector<pair<pii, int> > v;
	lcp[n + 1] = 0;
    sa[n + 1] = n;
    rep(i, 1, n + 1)
    {
        while (!v.empty() && v.back().X.Y > lcp[i])
        {
            pair<pii, int> &now = v.back();
            if (now.X.X < lcp[i])
            {
                ans += (now.X.Y - lcp[i]) * f(i - now.Y);
                now.X.Y = lcp[i];
            }
            else ans += (now.X.Y - now.X.X) * f(i - now.Y), v.pop_back();
        }
        v.push_back(mp(mp(lcp[i], n - sa[i]), i));
    }
    printf("%I64d", ans);
	return 0;
}