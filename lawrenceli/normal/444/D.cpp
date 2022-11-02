#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 50100;
const int MAXC = 70000;
const int MAXSQ = 230;
const int INF = 1e9;

int n, q, d;
string s;

map<string, int> mp;
int cnt;
string rev[MAXC];
int ind[MAXN][5];
vector<int> inds[MAXC];

int big[4*MAXSQ], bind[MAXC], cnt2;
int dist[4*MAXSQ][MAXC];

void setmin(int& a, int b) { if (a > b) a = b; }

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s;
    n = s.length();
    d = sqrt(n);
    memset(ind, -1, sizeof(ind));
    memset(bind, -1, sizeof(bind));
    for (int i=0; i<4*MAXSQ; i++)
        for (int j=0; j<MAXC; j++)
            dist[i][j] = INF;

    for (int len=1; len<=4; len++)
        for (int i=0; i+len<=s.length(); i++)
            mp[s.substr(i, len)] = 0;
    repi(i, mp) mp[i->fi] = cnt, rev[cnt] = i->fi, cnt++;
    assert(cnt < MAXC);
    for (int len=1; len<=4; len++)
        for (int i=0; i+len<=s.length(); i++) {
            ind[i][len] = mp[s.substr(i, len)];
            inds[ind[i][len]].push_back(i);
        }

    for (int i=0; i<cnt; i++)
        if (inds[i].size() >= d)
            big[cnt2] = i, bind[i] = cnt2, cnt2++;

    for (int i=0; i<cnt2; i++) {
        int l = rev[big[i]].length();
        for (int len=1; len<=4; len++) {
            int p = -1;
            for (int j=0; j+len<=s.length(); j++) {
                if (bind[ind[j][l]] == i) p = j;
                if (p != -1) setmin(dist[i][ind[j][len]], max(l, j+len-p));
            }
            p = -1;
            for (int j=int(s.length())-len; j>=0; j--) {
                if (bind[ind[j][l]] == i) p = j;
                if (p != -1) setmin(dist[i][ind[j][len]], max(len, p+l-j));
            }
        }
    }

    cin >> q;
    for (int i=0; i<q; i++) {
        string a, b;
        cin >> a >> b;
        if (!mp.count(a) || !mp.count(b)) {
            cout << "-1\n";
            continue;
        }
        int x = mp[a], y = mp[b];
        int al = a.length(), bl = b.length();
        if (bind[y] != -1) swap(a, b);
        if (bind[x] != -1) {
            int ans = dist[bind[x]][y];
            if (ans == INF) cout << "-1\n";
            else cout << ans << '\n';
            continue;
        }
        assert(!inds[x].empty());
        assert(!inds[y].empty());
        int p = 0, ans = INF;
        for (int i=0; i<inds[x].size(); i++) {
            while (p<inds[y].size() && inds[y][p]<inds[x][i]) p++;
            if (p<inds[y].size()) setmin(ans, max(al, inds[y][p]+bl-inds[x][i]));
            if (p>0) setmin(ans, max(bl, inds[x][i]+al-inds[y][p-1]));
        }
        if (ans == INF) cout << "-1\n";
        else cout << ans << '\n';
    }
    return 0;
}