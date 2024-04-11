#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    vector<ll> pref(n), suf(n);
    vector<int> left(n), right(n), st;
    st.reserve(n);

    for (int rot : {0, 1}) {
        auto &cur = rot == 0 ? pref : suf;
        auto &nearest = rot == 0 ? left : right;

        st.clear();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.back()] >= a[i])
                st.pop_back();

            nearest[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
            for (int j = 0; j < len(st); j++)
                cur[i] = max(cur[i], a[st[j]] * (i - (j == 0 ? -1 : st[j - 1])));
        }

        for (int i = 1; i < n; i++)
            cur[i] = max(cur[i], cur[i - 1]);

        reverse(all(a));
    }

    reverse(all(suf));
    reverse(all(right));
    for (auto &i : right)
        i = n - 1 - i;

    ll answer = pref.back();
    for (int i = 0; i < n - 1; i++)
        answer = max(answer, pref[i] + suf[i + 1]);

    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](const int i, const int j) {
        return a[i] < a[j];
    });

    for (int rot : {0, 1}) {
        vector<int> out_left(n), bad_right(n);
        iota(all(bad_right), 0);

        for (auto id : order) {
            int from = left[id] + 1, to = right[id];

            st.clear();
            for (int i = from; i < n; i++) {
                while (!st.empty() && a[st.back()] >= a[i] + a[id])
                    st.pop_back();

                out_left[i] = st.empty() ? from - 1 : st.back();
                while (!st.empty() && a[st.back()] >= a[i])
                    st.pop_back();

                st.push_back(i);
            }

            for (int i = from; i < to; i++)
                while (bad_right[i] < n && a[bad_right[i]] >= a[i] - a[id])
                    bad_right[i]++;

            for (int i = from; i < to; i++) {
                answer = max(answer, a[id] * (to - from) + (a[i] - a[id]) * (right[i] - left[i] - 1));
                answer = max(answer, a[id] * (min(to, right[i]) - from) + (a[i] - a[id]) * (bad_right[i] - left[i] - 1));
            }

            for (int i = from; i < n; i++)
                answer = max(answer, a[id] * (min(to, i) - from) + a[i] * (right[i] - out_left[i] - 1));
        }

        reverse(all(a));
        for (auto &i : order)
            i = n - 1 - i;

        swap(left, right);
        reverse(all(left));
        reverse(all(right));
        for (auto &i : left)
            i = n - 1 - i;

        for (auto &i : right)
            i = n - 1 - i;
    }
    cout << answer << '\n';
}