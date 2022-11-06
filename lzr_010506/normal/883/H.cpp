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
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n;
const int maxn = 400010;

char str[400010];
vector<int> rcnt[2];
int cnt[256], lef[256];
vector<int> V;
string ans[400010];
int zj[400010];

int main()
{
	n = read();
	scanf("%s", str + 1);
    int sqr = int(sqrt(n));
    rep(i, 1, n) cnt[str[i]] ++;
    rep(i, 0, 255)
    {
        if (!cnt[i]) continue;
        rcnt[cnt[i] &  1].pb(i);
    }
    rep(i, 1, sqr)
        if (n % i == 0) V.pb(i), V.pb(n / i);
    sort(V.begin(), V.end());
    sort(unique(V.begin(), V.end()), V.end());
    for (int i = 0; i < V.size(); i++)
    {
    	rep(i, 0, 255) lef[i] = cnt[i];
        bool okay = true;
        int bcnt = V[i], blen = n / V[i];
        if (blen & 1)
        {
            int jc = bcnt;
           	if (rcnt[1].size() > jc) okay = false;
           	else
           	{
                for (int j = 0; j < rcnt[1].size(); j++)
                {
                    zj[j+1] = rcnt[1][j];
                    lef[rcnt[1][j]] --;
                    jc --;
                }
                if (jc & 1)
                    okay = false;
                else
                {
                    int tin = 0;
                    rep(j, (int)rcnt[1].size() + 1, bcnt)
                    {
                        while (!lef[tin]) tin ++;
                        lef[tin] --;
                        zj[j] = tin;
                    }
                    rep(j, 1, bcnt)
                    {
                        int lfc = ((blen - 1) >> 1);
                        rep(k, 0, lfc - 1)
                        {
                            while (!lef[tin]) tin ++;
                            lef[tin] -= 2;
                            ans[j].pb(tin);
                        }
                        ans[j].pb(zj[j]);
                        rrep(k, lfc - 1, 0) ans[j].pb(ans[j][k]);
                    }
                    printf("%d\n", bcnt);
                    rep(j, 1, bcnt)
                        printf("%s ", ans[j].c_str());
                    return 0;
                }
            }
        }
        else
        {
            if (!rcnt[1].empty()) okay = false;
            else
            {
                int tin = 0;
                rep(j, 1, bcnt)
                {
                    int lfc = (blen >> 1);
                    rep(k, 0, lfc - 1)
                    {
                        while (!lef[tin]) tin ++;
                        lef[tin] -= 2;
                        ans[j].pb(tin);
                    }
                    rrep(k, lfc - 1, 0) ans[j].pb(ans[j][k]);
               	}
                printf("%d\n", bcnt);
                rep(j, 1, bcnt)
                    printf("%s ", ans[j].c_str());

                return 0;
            }
        }
    }
    return 0;
}