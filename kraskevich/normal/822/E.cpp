#include <bits/stdc++.h>    
using namespace std;

template<class T>
class SparseTable {
    vector<int> log;
    vector<vector<T>> value;

public:
    SparseTable() = default;

    SparseTable(const vector<T>& init_values) {
        int n = init_values.size();
        log.resize(n + 1);
        int cur = 0;
        for (int i = 0; i <= n; ++i) {
            while ((1 << (cur + 1)) <= i)
                ++cur;
            log[i] = cur;
        }
        int max_log = log[n];
        value.assign(max_log + 1, init_values);
        for (int h = 1; h <= max_log; ++h)
            for (int i = 0; i < n; ++i) {
                int l = i;
                int r = i + (1 << (h - 1));
                r = min(r, n - 1);
                value[h][i] = min(value[h - 1][l], value[h - 1][r]);
            }
    }

    T getMin(int L, int R) const {
        L = max(L, 0);
        R = min(R, (int)log.size() - 1);
        int h = log[R - L + 1];
        int l = L;
        int r = R - (1 << h) + 1;
        return min(value[h][l], value[h][r]);
    }
};



namespace SuffixArray {

    const int A = 256;

    struct SuffArray {
        int n;
        string s;
        vector<int> pos;
        vector<int> new_pos;
        vector<int> c;
        vector<int> new_c;
        vector<int> head;
        vector<int> cnt;
        vector<int> lcp;
        vector<int> rev;

        SuffArray(const string& str):  
                n(str.length()),
                s(str),
                pos(n),
                new_pos(n),
                c(n),
                new_c(n),
                head(max(A, n)),
                cnt(max(A, n)),
                lcp(max(0, n - 1)),
                rev(n) {
            build_array();
            for (int i = 0; i < n; i++)
                rev[pos[i]] = i;
            calc_lcp();
        }

    private:
        int low(int i, int step) {
            i -= step;
            if (i < 0)
                i += n;
            return i;
        }

        int high(int i, int step) {
            i += step;
            if (i >= n)
                i -= n;
            return i;
        }

        bool are_same(int p1, int p2, int step) {
            if (c[p1] != c[p2])
                return false;
            p1 = high(p1, step);
            p2 = high(p2, step);
            if (c[p1] != c[p2])
                return false;
            return true;
        }

        void build_array() {
            for (int i = 0; i < n; ++i)
                ++cnt[(int)s[i]];
            for (int i = 1; i < (int)head.size(); ++i)
                head[i] = head[i - 1] + cnt[i - 1];
            for (int i = 0; i < n; ++i) {
                c[i] = s[i];
                pos[head[c[i]]++] = i;
            }
            head[0] = 0;
            for (int i = 1; i < (int)head.size(); ++i)
                head[i] = head[i - 1] + cnt[i - 1];
            for (int step = 1; step <= n; step *= 2) {
                for (int i = 0; i < n; ++i) {
                    int cur = low(pos[i], step);
                    new_pos[head[c[cur]]++] = cur;
                }
                head[0] = 0;
                new_c[new_pos[0]] = 0;
                bool all_diff = true;
                for (int i = 1; i < n; ++i)
                    if (are_same(new_pos[i], new_pos[i - 1], step)) {
                        new_c[new_pos[i]] = new_c[new_pos[i - 1]];
                        all_diff = false;
                    }
                    else {
                        new_c[new_pos[i]] = new_c[new_pos[i - 1]] + 1;
                        head[new_c[new_pos[i]]] = i;
                    }
                c = new_c;
                pos = new_pos;
                if (all_diff)
                    break;
            }
        }

        void calc_lcp() {
            int curLen = 0;
            for (int i = 0; i < n; i++) {
                if (rev[i] == n - 1)
                    continue;
                int j = pos[rev[i] + 1];
                while (i + curLen < n && j + curLen < n && s[i + curLen] == s[j + curLen])
                    curLen++;
                lcp[rev[i]] = curLen;
                if (curLen > 0)
                    curLen--;
            }     
        }
    };
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int m;
    string t;
    cin >> m >> t;
    int x;
    cin >> x;
    string ss = s + "#" + t + "$";
    SuffixArray::SuffArray sa(ss);
    SparseTable<int> table(sa.lcp);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int p = 0; p < n; p++)
        for (int k = 0; k <= x; k++) {
            dp[p + 1][k] = max(dp[p + 1][k], dp[p][k]);
            int pos1 = sa.rev[p];
            int pos2 = sa.rev[dp[p][k] + s.length() + 1];
            if (pos1 > pos2)
                swap(pos1, pos2);
            assert (pos1 != pos2);
            int lcp = table.getMin(pos1, pos2 - 1);
            if (lcp)
                dp[p + lcp][k + 1] = max(dp[p + lcp][k + 1], dp[p][k] + lcp);
        }
    int res = 0;
    for (int i = 0; i <= n; i++)
        res = max(res, *max_element(dp[i].begin(), dp[i].end()));
    cout << (res == m ? "YES" : "NO") << "\n";
}