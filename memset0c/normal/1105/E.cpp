// =================================
//   author: memset0
//   date: 2019.01.26 13:36:04
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 45;
int n, m, ans;
bool G[N][N];
char s[N];
std::set <int> set;
std::map <std::string, int> map;

int id(std::string s) {
    static int cnt = 0;
    if (map.find(s) == map.end()) return map[s] = ++cnt;
    return map[s];
}

void dfs(std::vector <int> all, std::vector <int> some, std::vector <int> none) {
    // printf("dfs %d %d %d\n", all.size(), some.size(), none.size());
    // for (auto u : all) print(u, ' '); puts("");
    // for (auto u : some) print(u, ' '); puts("");
    // for (auto u : none) print(u, ' '); puts("");
    if (!some.size()) {
        if (!none.size()) ans = std::max(ans, (int)all.size());
        return;
    }
    int u = *some.begin();
    for (auto v : some) if (!G[u][v]) {
        std::vector <int> all_t = all, some_t, none_t;
        all_t.push_back(v);
        for (auto t : some) if (G[v][t]) some_t.push_back(t);
        for (auto t : none) if (G[v][t]) none_t.push_back(t);
        dfs(all_t, some_t, none_t);
        none.push_back(v);
    }
}

void main() {
    read(m), read(n);
    for (int i = 1, op; i <= m; i++)
        if (read(op), op == 1) {
            for (auto i : set)
                for (auto j : set)
                    G[i][j] = 1;
            set.clear();
        } else {
            scanf("%s", s);
            set.insert(id((std::string)s));
        }
    for (auto i : set)
        for (auto j : set)
            G[i][j] = 1;
    set.clear();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G[i][j] ^= 1;
    for (int i = 1; i <= n; i++) G[i][i] = 0;
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++)
    //         print((int)G[i][j], " \n"[j == n]);
    std::vector <int> all, some, none;
    for (int i = 1; i <= n; i++) some.push_back(i);
    dfs(all, some, none), print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }//fdjaifjidsjfoiasudifodusofuadsiofudsoifiodsfoipjfoioifjdsoifjiodsjvoidjfoihaoiufhfdoiufhaodsuifhiufrhoiufehgoiufdnh gfoiufdhiuglofdjhoig

/// gfmngksjdoifgjidofjgpoifdjgoiefrjigojsfdlogijdoflighdfloiugh