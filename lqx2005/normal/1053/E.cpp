// 19:14

#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define db double
#define ull unsigned long long
#define eb emplace_back
using namespace std;
const int N = 1e6 + 10;
int n;
int a[N], cnt[N], fa[N];
vector<int> id;
int stk[N], top, instk[N];
vector<int> pos[N];
int gf(int x) {return fa[x] == x ? x : fa[x] = gf(fa[x]); }
void quit() {
    cout << "no\n";
    exit(0);
}
int vld(int x, int y) {
    if(a[x] && a[y] && a[x] != a[y]) return 0;
    return 1;
}
void same(int x, int y) {
    a[x] = a[y] = a[x] | a[y];
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    FOR(i, 1, n * 2 - 1) {
        cin >> a[i];
    }
    FOR(i, 1, n * 2 - 1) fa[i] = i;
    FOR(i, 1, n * 2 - 1) if(a[i]) cnt[a[i]]++, pos[a[i]].emplace_back(i);
    FOR(i, 1, n) if(!cnt[i]) id.eb(i);
    FOR(i, 1, n) {
        FOR(j, 1, sz(pos[i]) - 1) {
            if((pos[i][j] - pos[i][j - 1]) & 1) {
                quit();
            }
        }
    }
    stk[++top] = 1;
    if(a[1]) instk[a[1]] = 1, cnt[a[1]]--;
    FOR(i, 2, n * 2 - 1) {
        if(a[i]) {
            cnt[a[i]]--;
            stk[++top] = i;
            if(instk[a[i]]) {
                vector<int> ma;
                ma.emplace_back(stk[top--]);
                while(top && a[stk[top]] != a[i]) ma.emplace_back(stk[top--]);
                ma.emplace_back(stk[top]);
                FOR(j, 0, (sz(ma) + 1) / 2 - 1) {
                    int x = ma[j], y = ma[sz(ma) - 1 - j];
                    if(!vld(x, y)) {
                        quit();
                    }
                    // cout << x <<" " << y << endl;
                    same(x, y);
                    if(!a[x]) {
                        a[x] = a[y] = id.back();
                        id.pop_back();
                    }
                }
            } else {
                instk[a[i]] = 1;
            }
        } else {
            if(a[stk[top]] && !cnt[a[stk[top]]] && top > 1) {
                fa[i] = stk[top - 1];
                top--;
            } else {
                stk[++top] = i;
            }
        }
    }
    FOR(i, 1, top) {
        if(!vld(stk[i], stk[top + 1 - i])) quit();
        same(stk[i], stk[top + 1 - i]);
        if(!a[stk[i]]) {
            a[stk[i]] = a[stk[top + 1 - i]] = id.back();
            id.pop_back();
        }
    }
    FOR(i, 1, n * 2 - 1) a[i] = a[gf(i)];
    cout << "yes\n";
    FOR(i, 1, n * 2 - 1) cout << a[i] <<" ";
    cout << "\n";
    return 0;
}