#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define Repd(i,n) for(int i=((int)(n))-1;i>=0;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

int n, m;
int a[100010];
int nxt[100010][26];
int F[100010][2];
long long G[100010][16];

long long calc(int i) {
    if (i >= n) {
        // Rep(t, n) { cerr << "=="; Rep(k, 2) cerr << F[t][k] << " "; cerr << endl; }
        if (F[n - 1][0] == n && F[n - 1][1] < n) return 1;
        return 0;
    }
    int v = 0;
    if (i > 0)
    Rep(k, 2) {
        int t = (F[i-1][k] >= i-2 && F[i-1][k] <= i) ? i - F[i-1][k] : 3;
        v = v * 4 + t;
    }
    // verify(v < 16);
    long long &res = G[i][v];
    if (res != -1) return res;
    res = 0;
    Rep(c, m) {
        F[i][0] = (i == 0) ? nxt[i][c] : (F[i - 1][0] == n ? n : nxt[F[i - 1][0] + 1][c]);
        F[i][1] = (i == 0) ? -1 : (F[i - 1][1] == n ? n : nxt[F[i - 1][1] + 1][c]);
        if (i > 0 && F[i][1] > F[i-1][0]) F[i][1] = F[i-1][0];
        long long add = calc(i + 1);
        res += add;
        // Rep(t, i) cerr << " ";
        // cerr << i << " " << c << " " << add << endl;
    }
    return res;
}

int main() {
    cin >> n >> m;
    string s;
    cin >> s;
    Rep(i, n) a[i] = s[i] - 'a';
    int cur[26];
    Rep(i, 26) {
        cur[i] = n;
        nxt[n][i] = n;
    }
    Ford(i, n - 1, 0) {
        cur[a[i]] = i;
        Rep(j, 26) nxt[i][j] = cur[j];
    } 
    memset(G, -1, sizeof(G));
    long long res = calc(0);
    cout << res << endl;
    return 0;
}