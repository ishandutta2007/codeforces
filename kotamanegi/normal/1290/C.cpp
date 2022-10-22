#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(100);
}
#define int ll
pair<int, int> union_tree[1000000];
int union_find(int now) {
    if (union_tree[now].first == now) return now;
    return union_tree[now].first = union_find(union_tree[now].first);
}
void union_merge(int a, int b) {
    a = union_find(a);
    b = union_find(b);
    if (a == b) return;
    union_tree[a].second += union_tree[b].second;
    union_tree[b].first = a;
    return;
}
vector<int> vertexs[400000];
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    REP(i, k) {
        union_tree[i * 2] = mp(i*2, 0);
        union_tree[i * 2 + 1] = mp(i*2+1, 1);
    }
    union_tree[400000 * 2] = mp(400000 * 2, 0);
    union_tree[400000 * 2 + 1] = mp(400000 * 2 + 1, 1e9);
    REP(i, k) {
        int a;
        cin >> a;
        REP(t, a) {
            int b;
            cin >> b;
            b--;
            vertexs[b].push_back(i);
        }
    }
    int now_ans = 0;
    for (int i = 0; i < n; ++i) {
        if (vertexs[i].size() != 0) {
            if (vertexs[i].size() == 1) {
                vertexs[i].push_back(400000);
            }
            {
                int a = union_find(vertexs[i][0] * 2);
                int b = union_find(vertexs[i][0] * 2 + 1);
                now_ans -= min(union_tree[a].second, union_tree[b].second);
            }

            if(union_find(vertexs[i][0]*2) != union_find(vertexs[i][1]*2)&&union_find(vertexs[i][0] * 2) != union_find(vertexs[i][1]*2+1)){
                int a = union_find(vertexs[i][1] * 2);
                int b = union_find(vertexs[i][1] * 2 + 1);
                now_ans -= min(union_tree[a].second, union_tree[b].second);
            }
            if (s[i] == '0') {
                //need to differ
                union_merge(vertexs[i][0] * 2, vertexs[i][1] * 2 + 1);
                union_merge(vertexs[i][0] * 2 + 1, vertexs[i][1] * 2);
            }
            else {
                union_merge(vertexs[i][0] * 2, vertexs[i][1] * 2);
                union_merge(vertexs[i][0] * 2 + 1, vertexs[i][1] * 2 + 1);
            }
            int a = union_find(vertexs[i][0] * 2);
            int b = union_find(vertexs[i][0] * 2 + 1);
            now_ans += min(union_tree[a].second, union_tree[b].second);
        }
        cout << now_ans << endl;
    }
    return;
}
#undef int
int main() {
    init();
    solve();
}