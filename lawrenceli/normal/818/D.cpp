#include <bits/stdc++.h>

using namespace std;

int n, A, ar[100100];
int freq[1000100];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> A;
    set<pair<int, int> > st;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        st.insert(make_pair(0, ar[i]));
    }
    for (int i = 0; i < n; i++) {
        int c = ar[i];
        auto it = st.find(make_pair(freq[c], c));
        if (it != st.end()) {
            assert(it->second == c);
            freq[c]++;
            st.erase(it);
            st.insert(make_pair(freq[c], c));
        }

        if (c == A) {
            while (st.begin()->first < freq[c]) st.erase(st.begin());
        }
    }

    if (!st.empty() && st.begin()->second == A) st.erase(st.begin());
    if (st.empty()) cout << "-1";
    else cout << st.begin()->second << '\n';
}