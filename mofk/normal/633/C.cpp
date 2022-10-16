#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M;
string s, a[100005], b[100005];
int prv[10005];
int child[1000005][26];
int sz = 1;
int root[1000005];
int nxt[10005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> s >> M; s = '~' + s;
    ff(i, 1, M) cin >> b[i], a[i] = b[i];
    ff(i, 1, M) ff(j, 0, (int)a[i].size() - 1) if (a[i][j] < 'a') a[i][j] -= 'A'; else a[i][j] -= 'a';
    ff(i, 1, M) {
        int cur = 1;
        ff(j, 0, (int)a[i].size() - 1) {
            if (!child[cur][a[i][j]]) child[cur][a[i][j]] = ++sz;
            cur = child[cur][a[i][j]];
        }
        root[cur] = i;
    }
    ff(i, 1, N) prv[i] = -1;
    ff(i, 1, N) {
        int cur = 1;
        fb(j, i - 1, max(0, i - 1000)) {
            cur = child[cur][s[j+1] - 'a'];
            if (!cur) break;
            if (prv[j] >= 0 && root[cur]) {
                prv[i] = j;
                nxt[i] = root[cur];
                break;
            }
        }
    }
    int cur = N;
    vi ans;
    while (cur) {
        ans.pb(nxt[cur]);
        cur = prv[cur];
    }
    fb(i, (int)ans.size() - 1, 0) cout << b[ans[i]] << ' ';
    cout << endl;
    return 0;
}