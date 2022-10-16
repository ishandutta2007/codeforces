/*input
10
+ 8
+ 9
+ 11
+ 6
+ 1
? 3
- 8
? 3
? 8
? 11
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif

struct Node {
    Node *child[2];
    int cnt = 0;
    Node() {
        for (int i = 0; i < 2; i++) child[i] = NULL;
    }
} * root = new Node();

void add(int x) {
    Node *cur = root;
    for (int i = 30; i >= 0; i--) {
        int b = bit(x, i);
        if (cur->child[b] == NULL)
            cur->child[b] = new Node();
        cur = cur->child[b];
        cur->cnt++;
    }
}

void del(int x) {
    Node *cur = root;
    for (int i = 30; i >= 0; i--) {
        int b = bit(x, i);
        cur = cur->child[b];
        cur->cnt--;
    }
}

long long ans = 0;
void dfs(Node * cur, long long val, long long pos) {
    if (pos == -1) {
        ans = max(ans, val);
        return;
    }
    int t = bit(val, pos);
    if (t == 0) {
        if (cur -> child[1] != NULL && cur -> child[1]->cnt != 0) {
            val ^= (1LL << pos);
            cur = cur -> child[1];
        }
        else {
            cur = cur -> child[0];
        }
        dfs(cur, val, pos - 1);
    }
    else {
        if (cur -> child[0] != NULL && cur->child[0]->cnt != 0) {
            cur = cur -> child[0];
        }
        else {
            val ^= (1LL << pos);
            cur = cur -> child[1];
        }
        dfs(cur, val, pos - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    add(0);
    while (q--) {
        char c; cin >> c;
        if (c == '+') {
            int t; cin >> t;
            add(t);
        }
        else if (c == '-') {
            int t; cin >> t;
            del(t);
        }
        else {
            int t; cin >> t;
            ans = 0;
            dfs(root, t, 30);
            cout << ans << endl;
        }
    }
}