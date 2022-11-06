#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls x << 1
#define rs x << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;
set<pii> vis;
map<pii, int> step;
queue<pii> q;
const int dd[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1} , {1, 0} , {1, 1}};
pii st, ed;
int n, a, b, r;
int main()
{
    st.X = read();
    st.Y = read();
    ed.X = read();
    ed.Y = read();
    n = read();
    vis.insert(st);
    vis.insert(ed);
    rep(i, 1, n)
    {
    	r = read();
    	a = read();
    	b = read();
    	rep(i, a, b) vis.insert(mp(r , i));
    }
    q.push(st);
    while (!q.empty())
    {
        pii go, now = q.front();
        int nstep = step[now];
        q.pop();
       	rep(d, 0, 7)
        {
            go = mp(now.X + dd[d][0], now.Y + dd[d][1]);
            if (vis.find(go) != vis.end() && step.find(go) == step.end())
            {
                step[go] = nstep + 1;
                q.push(go);
                if (go == ed)
                {
                    cout << nstep + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}