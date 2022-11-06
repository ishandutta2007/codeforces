#include <bits/stdc++.h>

using namespace std;

const int N = 200005, BASE = 2 * 131072;
const long long INF = 1e18;

int n, m, k, a, b;
int cost[N];
int t[N];
int posInTree[N];
pair<long long, int> tree[2 * BASE + 5];

bool likedByFirst[N], likedBySecond[N];
vector<int> first, second, both, none;

long long query(int pos, int c) {
    if (c == 0) return 0;
    if (c > tree[pos].second) {
        return INF;
    }
    if (pos >= BASE) {
        return tree[pos].first;
    }
    if (tree[pos * 2].second >= c) {
        return query(pos * 2, c);
    } else {
        return tree[pos * 2].first + query(pos * 2 + 1, c - tree[pos * 2].second);
    }
}

pair<long long, int> merge(pair<long long , int> A, pair<long long, int> B) {
    pair<long long, int> ret;
    ret.first = A.first + B.first;
    ret.second = A.second + B.second;
    return ret;
}

void insert(int pos, int w) {
    pos += BASE;
    tree[pos] = {w, 1};
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
        pos /= 2;
    }
}

void remove(int pos) {
    pos += BASE;
    tree[pos] = {0, 0};
    pos /= 2;
    while (pos >= 1) {
        tree[pos] = merge(tree[pos * 2], tree[pos * 2 + 1]);
        pos /= 2;
    }
}

bool cmp(int a, int b) {
    return cost[a] < cost[b];
}

int main() {
  
    scanf("%d %d %d", &n, &m, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }
    
    for (int i = 1; i <= n; i++) t[i] = i;
    
    sort(t + 1, t + 1 + n, cmp);
    
    for (int i = 1; i <= n; i++) {
        posInTree[t[i]] = i;
    }
    
    scanf("%d", &a);
    for (int i = 1; i <= a; i++) {
        int x;
        scanf("%d", &x);
        likedByFirst[x] = true;
    } 
    
    scanf("%d", &b);
    for (int i = 1; i <= b; i++) {
        int x;
        scanf("%d", &x);
        likedBySecond[x] = true;
    } 
    
    for (int i = 1; i <= n; i++) {
        if (likedBySecond[t[i]] && likedByFirst[t[i]]) {
            both.push_back(t[i]);
        }
        if (likedByFirst[t[i]] && !likedBySecond[t[i]]) {
            first.push_back(t[i]);
        }
        if (!likedByFirst[t[i]] && likedBySecond[t[i]]) {
            second.push_back(t[i]);
        }
        if (!likedByFirst[t[i]] && !likedBySecond[t[i]]) {
            none.push_back(t[i]);
        }
    }
    
    while (both.size() > m) {
        both.pop_back();
    }
    
    for (int i = 0; i < both.size(); i++) {
        insert(posInTree[both[i]], cost[both[i]]);
    }
    
    for (int i = 0; i < none.size(); i++) {
        insert(posInTree[none[i]], cost[none[i]]);
    }
    
    for (int i = k; i < first.size(); i++) {
        insert(posInTree[first[i]], cost[first[i]]);
    }
    
    for (int i = k; i < second.size(); i++) {
        insert(posInTree[second[i]], cost[second[i]]);
    }
    
    long long ans = INF;
    long long sum = 0;
    for (int i = 0; i < min((int)first.size(), k); i++) {
        sum += cost[first[i]];
    }
    
    for (int i = 0; i < min((int)second.size(), k); i++) {
        sum += cost[second[i]];
    }
    
    if (first.size() >= k && second.size() >= k && 2 * k <= m) {
        ans = min(ans, sum + query(1, m - 2 * k));
    }

    for (int i = 0; i < both.size(); i++) {
        sum += cost[both[i]];
        remove(posInTree[both[i]]);
        if (k - i - 1 >= 0 && k - i - 1 < (int)first.size()) {
            sum -= cost[first[k - i - 1]];
            insert(posInTree[first[k - i - 1]], cost[first[k - i - 1]]);
        }
        if (k - i - 1 >= 0 && k - i - 1 < (int)second.size()) {
            sum -= cost[second[k - i - 1]];
            insert(posInTree[second[k - i - 1]], cost[second[k - i - 1]]);
        }
        if ((int)first.size() >= k - i - 1 && (int)second.size() >= k - i - 1 && i + 1 + 2 * max(0, (k - i - 1)) <= m) {
            ans = min(ans, sum + query(1, m - i - 1 - 2 * max(0, (k - i - 1))));
        }
    }
    
    if (ans >= INF) {
        printf("-1\n"); 
    } else {
        printf("%lld\n", ans);
    }
    
    return 0;
}