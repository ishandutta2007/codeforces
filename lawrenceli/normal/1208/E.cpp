#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int maxn = 1000100;

int n, w;
vector<piii> events[maxn];
multiset<int> st[maxn];

int main() {
    scanf("%d %d", &n, &w);
    w += 2;
    for (int i = 0; i < n; i++) {
        int l; scanf("%d", &l);
        l += 2;
        for (int j = 0; j < l; j++) {
            int a;
            if (j == 0 || j == l-1) a = 0;
            else scanf("%d", &a);
            events[j].push_back(piii(i, pii(a, 1)));
            events[w-l+j+1].push_back(piii(i, pii(a, 0)));
        }
    }

    long long sum = 0;
    for (int i = 0; i < w; i++) {
        for (auto p : events[i]) {
            int j = p.first;
            int a = p.second.first;
            int b = p.second.second;
            if (!st[j].empty()) sum -= *st[j].rbegin();
            if (b) st[j].insert(a);
            else st[j].erase(st[j].find(a));
            if (!st[j].empty()) sum += *st[j].rbegin();
        }

        if (i > 0 && i < w - 1)
            printf("%lld ", sum);
    }
}