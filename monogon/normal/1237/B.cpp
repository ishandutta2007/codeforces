
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, a[N], b[N], ainv[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ainv[a[i]] = i;
    }
    stack<int> st;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = ainv[b[i]];
        while(st.size() && st.top() > b[i]) {
            st.pop();
        }
        st.push(b[i]);
    }
    cout << n - st.size() << endl;
}