#include <bits/stdc++.h>

using namespace std;

const long long linf = 3e12;
int n;
long long a[1000006];
long long b[1000006];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], a[i] -= i;
    stack<pair<int, long long>> st;
    st.push({-1, linf});
    st.push({0, a[0]});
    for (int i = 1; i < n; ++i) {
        long long rem = a[i] - st.top().second;
        long long cur_h = st.top().second;
        st.pop();
        while (true) {
            long long new_h = st.top().second;
            long long new_t = st.top().first;
            long long need = (new_h - cur_h) * (i - new_t);
            if (st.top().first != -1 && need <= rem) {
                rem -= need;
                cur_h = new_h;
                st.pop();
            }
            else {
                long long add = rem / (i - new_t);
                int spare = rem % (i - new_t);
                if (spare) st.push({new_t + spare, cur_h + add + 1});
                st.push({i, cur_h + add});
                break;
            }
        }
    }
    long long cur_h = st.top().second;
    int last = n - 1;
    st.pop();
    while (st.size()) {
        int fr = st.top().first;
        for (int i = fr + 1; i <= last; ++i) b[i] = cur_h + i;
        cur_h = st.top().second;
        last = fr;
        st.pop();
    }
    for (int i = 0; i < n; ++i) cout << b[i] << ' '; cout << endl;
    return 0;
}