#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define ld long double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pi complex<ld>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
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

int fp, lp, len;
char ch[200010];

stack<int> w0, w1;
vector<int> v[200010];

int main()
{
    scanf("%s", ch);
    len = (int) strlen(ch);
    rep(i, 0, len - 1)
    {
        if (ch[i] == '1')
        {
            if (w0.empty())
            {
                cout << -1 << endl;
                return 0;
            }
            int t = w0.top();
            w0.pop();
            v[t].pb(i);
            w1.push(t);
        }
        else
        {
            if (!w1.empty())
            {
                int t = w1.top();
                w1.pop();
                v[t].push_back(i);
                w0.push(t);
            }
            else
            {
                w0.push(i);
                v[i].push_back(i);
            }
        }
    }
    if (!w1.empty()) puts("-1");
    else
    {
        cout << sz(w0) + sz(w1) << endl;
        rep(i, 0, len - 1)
        {
            if (v[i].empty()) continue;
            cout << sz(v[i]) << " ";
            int nn = sz(v[i]);
            rep(j, 0, nn - 1)
            {
                int t = v[i][j];
                cout << t + 1 << " ";
            }
            puts("");
        }
    }
    return 0;
}