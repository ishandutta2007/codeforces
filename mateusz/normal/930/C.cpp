#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
int a, b;

int cnt[N];

vector<int> findLongest() {
    vector<int> ret;
    vector<int> v;
    for (int i = 1; i <= m; i++) {
        int low = 0;
        int high = (int)v.size() - 1;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (v[mid] <= cnt[i]) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        res++;
        if (res == v.size()) {
            v.push_back(cnt[i]);
        } else {
            v[res] = cnt[i];
        }
        ret.push_back(res + 1);
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);
        cnt[a]++;
        cnt[b + 1]--;
    }
    
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }
    
    vector<int> x = findLongest();
    reverse(cnt + 1, cnt + 1 + m);
    vector<int> y = findLongest();
    reverse(y.begin(), y.end());
    
    int ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, x[i] + y[i + 1]);
    }
    ans = max(ans, max(x[m - 1], y[0]));
    
    printf("%d\n", ans);
    return 0;
}