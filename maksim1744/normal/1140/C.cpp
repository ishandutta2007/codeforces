/*
    23.03.2019 16:17:19
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    int n, k;
    cin >> n >> k;
    vector< pair< long long, long long > > songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i].second >> songs[i].first;
    }
    sort(songs.begin(), songs.end());
    multiset< long long > st;
    long long sm = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (st.size() == k && songs[i].second < *st.begin())
            continue;
        st.insert(songs[i].second);
        sm += songs[i].second;
        if (st.size() == k + 1) {
            sm -= *st.begin();
            st.erase(st.begin());
        }
        ans = max(ans, sm * songs[i].first);
    }
    cout << ans << '\n';
    return 0;
}