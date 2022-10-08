#include <bits/stdc++.h>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define Repd(i,n) for(int i=((int)(n))-1;i>=0;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Fit(i,c) for(decltype(c.begin()) i=c.begin();i!=c.end();++i)
#define Fid(i,c) for(decltype(c.rbegin()) i=c.rbegin();i!=c.rend();++i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

#define maxn 100010

int n;
LL a[maxn];
int p[maxn];
LL s[maxn];
VI children[maxn];

void dfs(int i, int h, LL sum) {
    if (s[i] == -1) {
        LL mini = -1;
        Rep(k, children[i].size()) {
            int j = children[i][k];
            LL x = s[j] - sum;
            if (mini == -1) mini = x;
            else mini = min(mini, x);
        }
        if (mini == -1) a[i] = 0;
        else a[i] = mini;
    } else {
        a[i] = s[i] - sum;
    }
    Rep(k, children[i].size()) {
        int j = children[i][k];
        dfs(j, h + 1, sum + a[i]);
    }
}

int main() {
    cin >> n;
    For(i, 1, n-1) {
        cin >> p[i];
        p[i]--;
        children[p[i]].pb(i);
    }
    Rep(i, n) cin >> s[i];
    dfs(0, 1, 0);
    int invalid = false;
    Rep(i, n) if (a[i] < 0) invalid = true;
    if (invalid) cout << -1 << endl;
    else cout << accumulate(a, a + n, 0LL) << endl;
    return 0;
}