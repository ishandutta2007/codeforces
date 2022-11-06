#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n;
char s[2005], t[2005], tmp[2005];
int bal[26];
vector<int> ans;
int done = 0;

void makeShift(int cnt)
{
    ans.pb(cnt);
    int ind = 0;
    rep(i, 0,  cnt - 1)
        tmp[ind ++] = s[n - 1 - i];
    rep(i, 0, n - cnt - 1)
        tmp[ind ++] = s[i];
    rep(i, 0, n - 1) s[i] = tmp[i];
}

void step(char c)
{
    int pos = done;
    while (pos < n && s[pos] != c) pos ++;
    assert(pos < n);
    int need = n - 1 - pos;
    if (need > 0) makeShift(need);
    if (n - done - need > 0) makeShift(n - done - need);
    if (done > 0) makeShift(done);
    done ++;
}

int main()
{
    scanf("%d%s%s", &n, s, t);
    rep(i, 0, n - 1) bal[s[i] - 'a'] ++;
    rep(i, 0, n - 1) bal[t[i] - 'a'] --;
    rep(i, 0, 25)
    	if (bal[i] != 0)
    	{
        	cout << -1 << endl;
        	return 0;
    	}
    int l = n / 2 - 1;
    int r = l + 1;
    int cur = n % 2;
    rep(i, 0, n - 1)
    {
        if (!cur)
        {
            step(t[l]);
            l --;
        }
        else
        {
            step(t[r]);
            r ++;
        }
        cur ^= 1;
    }
    rep(i, 0, n - 1) assert(s[i] == t[i]);
    printf("%d\n", (int)ans.size());
    for (int x : ans)
        printf("%d ", x);
    puts("");
    return 0;
}