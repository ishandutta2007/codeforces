#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

int m[max_n];
int cnt[max_n];
int n, op;
int sh[max_n];
int a[max_n];
bool vis[max_n];

int min_oper(int shift) {
    for (int i = 0; i < n; ++i) {
        a[i] = m[(shift + i) % n];
        vis[i] = 0;
    }
    int ans =0 ;
    for (int i = 0; i < n; ++i) {
        vis[i] = 1;
        int cur = a[i];
        int len = 1;
        while(!vis[cur]) {
            vis[cur] = 1;
            ++len;
            cur = a[cur];
        }
        ans += len - 1;
    }
    //cout << "$$ " << ans;
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> op;
        for (int i = 0; i < n; ++i) {
            m[i] = cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
            --m[i];
            sh[i] = (i - m[i] + n) % n;
            cnt[sh[i]]++;
        }
        vector<int> ans;
        int max_spoiled = op * 2;
        for (int shift = 0; shift < n; ++shift) {
            int spoiled = n - cnt[shift];
            if (spoiled > max_spoiled) {
                continue;
            }
            if (min_oper(shift) <= op) {
                ans.push_back(shift);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << " ";
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << "\n";
    }
    return 0;
}