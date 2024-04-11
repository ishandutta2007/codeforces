#include <bits/stdc++.h>

using namespace std;

int a[300005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        stack<int> st;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (st.empty() || st.top() > a[i]) st.push(a[i]);
            else {
                int last = a[i];
                while (st.size() > 0 && st.top() < a[i]) last = st.top(), st.pop();
                st.push(last);
            }
        }
        cout << (st.size() == 1 ? "YES" : "NO") << endl;
    }
    return 0;
}