#include <bits/stdc++.h>
#include <math.h>
#define uint unsigned long long
#define ll long long
#define ui unsigned int
#define db double
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
#define REP(f, g) rep(f, 0, g - 1)
#define bc(x) __builtin_popcount(x)
#define ept 1e-9
using namespace std;
inline int read()
{
		int x = 0, f = 1; char ch = getchar();
		while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
		while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
		return x * f;
}
const ui one = 0x00000001;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
vector<vector<set<int> > > dt;
vector<string> ch;
ui nset;
int n, m, k, nr, nc;
struct Node
{
    Node() : r(-1), c(-1), mask(-1), path(""), let('A'), d(0) {}	
    int r, c, d;
    ui mask;
    string path;
    char let;
    Node(int R, int C, ui Ns, string Np, char Nl, int Nd) : r(R), c(C), mask(Ns), path(Np), let(Nl), d(Nd) {}
    bool operator < (const Node & x) const
    {
    	if(d == x.d)
    		if(path == x.path) return let >= x.let;
    		else return path >= x.path;
    	return d >= x.d;
    }
}now;

priority_queue<Node> q;
vector<Node> pv, tv;
bool check(int r, int c, ui mask)
{
    ui subset = mask;
    do
    {
        subset = (subset - 1) & mask;
        if(dt[r][c].find(subset) != dt[r][c].end()) return 1;
    } while (subset != mask);
    return 0;
}

int main()
{
    cin >> n >> m >> k;
    ch.resize(n);
    REP(i, n) cin >> ch[i];
    dt.resize(n);
    REP(i, n) dt[i].resize(m);
    int sr, sc;
    REP(i, n)
        REP(j, m)
            if(ch[i][j] == 'S') {sr = i; sc = j; break;}
    q.push(Node(sr, sc, 0, "", 'a', 0));
    dt[sr][sc].insert(0);
    while(!q.empty())
    {
        pv.clear();
        now = q.top();
        REP(i, 4)
        {
            nr = now.r + dx[i];
            nc = now.c + dy[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(ch[nr][nc] == 'T') { cout << now.path; return 0; }
            nset = now.mask | (one << int(ch[nr][nc] - 'a'));
            if((bc(nset) > k) || check(nr, nc, nset)) continue;
            pv.pb(Node(nr, nc, nset, now.path + ch[nr][nc], ch[nr][nc], now.d + 1));
            dt[nr][nc].insert(nset);
        }
        sort(pv.begin(), pv.end());
        REP(i, (int)pv.size()) q.push(pv[i]);
        q.pop();
    }
    cout << -1;
    return 0;
}