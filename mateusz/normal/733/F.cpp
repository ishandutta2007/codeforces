#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m;
long long weight[N];
int cost[N];
long long S;
int rep[N];
bool taken[N];
int t[N];
int ans[N];
pair<int, int> edge[N];

int calcMid(pair<int, int> p) {
    return (p.first + p.second) / 2;
}

bool cmp(pair<pair<int, int>, int> A, pair<pair<int, int>, int> B) {
    int mid1 = calcMid(A.first);
    int mid2 = calcMid(B.first);
    return mid1 < mid2;
}

int find(int w) {
    return w == rep[w] ? w : rep[w] = find(rep[w]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    rep[a] = b;
}

bool cmp2(int a, int b) {
    return weight[a] < weight[b];
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &weight[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &cost[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &edge[i].first, &edge[i].second);
    }
    scanf("%lld", &S);
    for (int i = 1; i <= m; i++) {
        t[i] = i;
    }
    sort(t + 1, t + 1 + m, cmp2);

    for (int i = 1; i <= n; i++) {
        rep[i] = i;
    }

    long long total = 0;
    for (int i = 1; i <= m; i++) {
        int from = edge[t[i]].first;
        int to = edge[t[i]].second;
        if (find(from) != find(to)) {
            Union(from, to);
            taken[t[i]] = true;
            total += weight[t[i]];
        }
    }
    vector<pair<pair<int, int>, int> > binsearch;
    long long best = total;
    int whichEdge = -1;
    for (int i = 1; i <= m; i++) {
        if (taken[t[i]]) {
            long long newSum = total - S / cost[t[i]];
            if (newSum < best) {
                best = newSum;
                whichEdge = t[i];
            }
        } else {
            binsearch.push_back({{0, i - 1}, i});
        }
    }


    while (!binsearch.empty()) {
        for (int i = 1; i <= n; i++) {
            rep[i] = i;
        }
        sort(binsearch.begin(), binsearch.end(), cmp);
        vector<pair<pair<int, int>, int> > newBinsearch;
        int cur = 0;
        static int x = 0;
        x++;
        for (int i = 1; i <= m; i++) {
            while (cur < binsearch.size() && calcMid(binsearch[cur].first) < i) {
                int from = edge[t[binsearch[cur].second]].first;
                int to = edge[t[binsearch[cur].second]].second;
                int mid = calcMid(binsearch[cur].first);
                if (find(from) != find(to)) {
                    ans[t[binsearch[cur].second]] = mid;
                    int low = mid + 1;
                    int high = binsearch[cur].first.second;
                    if (low <= high) {
                        newBinsearch.push_back({{low, high}, binsearch[cur].second});
                    }
                } else {
                    int high = mid - 1;
                    int low = binsearch[cur].first.first;
                    if (low <= high) {
                        newBinsearch.push_back({{low, high}, binsearch[cur].second});
                    }
                }
                cur++;
            }
            int from = edge[t[i]].first;
            int to = edge[t[i]].second;
            if (find(from) != find(to)) {
                Union(from, to);
            }
        }
        binsearch = newBinsearch;
    }

    for (int i = 1; i <= m; i++) {
        if (!taken[t[i]]) {
            long long newSum = total - weight[t[ans[t[i]]]] + weight[t[i]] - S / cost[t[i]];
            if (newSum < best) {
                best = newSum;
                whichEdge = t[i];
            }
        }
    }

    if (whichEdge != -1) {
        weight[whichEdge] -= S / cost[whichEdge];
    }

    for (int i = 1; i <= n; i++) {
        rep[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        taken[i] = false;
    }
    sort(t + 1, t + 1 + m, cmp2);
    long long res = 0;
    for (int i = 1; i <= m; i++) {
        int from = edge[t[i]].first;
        int to = edge[t[i]].second;
        if (find(from) != find(to)) {
            Union(from, to);
            res += weight[t[i]];
            taken[t[i]] = true;
        }
    }

    printf("%lld\n", res);
    for (int i = 1; i <= m; i++) {
        if (taken[i]) {
            printf("%d %lld\n", i, weight[i]);
        }
    }

    return 0;
}