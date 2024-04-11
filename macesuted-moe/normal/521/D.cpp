#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

typedef pair<int, int> pii;
typedef pair<double, int> pdi;

const int maxn = 100005;

pii as[maxn];
vector<pii> plu[maxn];
vector<pdi> multi;
vector<int> ans;
int a[maxn], opt[maxn];

inline bool cmp(int x, int y) { return opt[x] < opt[y]; }

int main() {
    int k = read<int>(), n = read<int>(), m = read<int>();
    for (int i = 1; i <= k; i++) a[i] = read<int>();
    for (int i = 1; i <= n; i++) {
        opt[i] = read<int>();
        int x = read<int>(), y = read<int>();
        if (opt[i] == 1) as[x] = max(as[x], (pii){y, i});
        if (opt[i] == 2) plu[x].push_back((pii){y, i});
        if (opt[i] == 3) multi.push_back((pii){y, i});
    }
    for (int i = 1; i <= k; i++)
        if (as[i].first > a[i]) plu[i].push_back((pii){as[i].first - a[i], as[i].second});
    for (int i = 1; i <= k; i++) {
        sort(plu[i].begin(), plu[i].end(), greater<pii>());
        long long num = a[i];
        for (vector<pii>::iterator p = plu[i].begin(); p != plu[i].end(); p++)
            multi.push_back((pdi){1.0 * (num + p->first) / num, p->second}), num += p->first;
    }
    sort(multi.begin(), multi.end(), greater<pdi>());
    m = min((int)multi.size(), m);
    printf("%d\n", m);
    for (int i = 0; i < m; i++) ans.push_back(multi[i].second);
    sort(ans.begin(), ans.end(), cmp);
    for (vector<int>::iterator i = ans.begin(); i != ans.end(); i++) printf("%d ", *i);
    puts("");
    return 0;
}