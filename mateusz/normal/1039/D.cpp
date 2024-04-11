#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, s;
int a, b;
int K, ret;
bool vis[N];
int maxPath[N];
int ans[N];
vector<int> V[N];
int preorder[N];
int preTime;

void dfs(int w) {
    preorder[++preTime] = w;
    vis[w] = true;
    for (int i = V[w].size() - 1; i >= 0; i--) {
        int u = V[w][i];
        if (vis[u]) {
            swap(V[w][i], V[w].back());
            V[w].pop_back();
            continue;
        }
        dfs(u);
    }
}

int solve(int k) {
    ret = 0;
    K = k;
    
    for (int i = n; i >= 1; i--) {
        int w = preorder[i];
        maxPath[w] = 1;
        bool done = false;
        for (int u : V[w]) {
            if (maxPath[w] + maxPath[u] >= K) {
                maxPath[w] = 0;
                ret++;
                done = true;
                break;
            }
            maxPath[w] = max(maxPath[w], maxPath[u] + 1);
        }
        if (!done && maxPath[w] >= K) {
            maxPath[w] = 0;
            ret++;
        }
    }
    
    return ret;
}

int main() {
    
    scanf("%d", &n);
    int l = 1;
    int w = n;
    while (w) {
        w >>= 1;
        l++;
    }
    s = (int)sqrt(n*l);
    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    dfs(1);
    
    ans[1] = n;
    for (int i = 2; i <= s; i++) {
        ans[i] = solve(i);
    }
    
    int max_ans = n / (s + 1);
    int last = s;
    vector<int> nexts;
    nexts.push_back(s);
    set<pair<int, int > > visited;
    for (int i = max_ans; i >= 0; i--) {
        auto it = visited.upper_bound({-i, n});
        auto it2 = it;
        int low = last + 1;
        if (it != visited.begin()) {
            --it2;
            low = max(low, it2->second + 1);
        }
        int high = n;
        if (it != visited.end()) {
            high = it->second - 1;
        }
        int res = low - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int paths = solve(mid);
            visited.insert({-paths, mid});
            if (paths >= i) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        nexts.push_back(max(nexts.back(), res));
        last = res;
    }
    
    int cnt = 0;
    for (int i = nexts.size() - 1; i >= 1; i--) {
        for (int j = nexts[i]; j > nexts[i - 1]; j--) {
            ans[j] = cnt;
        }
        cnt++;
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]); 
    }
    
    return 0;
}