#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <set>

using namespace std;

const int MAXN = 200100;

int n, m, k;
multiset<int> st;
int arr[MAXN], freq[MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;
    for (int i=0; i<n; i++) cin >> arr[i];

    int lt = 0, rt = 0, ans = 0;

    for (int i=0; i<m; i++) st.insert(0);

    while (lt < n) {
        if (rt == n || rt - lt - *st.rbegin() > k) {
            ans = max(ans, *st.rbegin());
            st.erase(st.find(freq[arr[lt]]));
            freq[arr[lt]] --;
            st.insert(freq[arr[lt]]);
            lt++;
        } else {
            st.erase(st.find(freq[arr[rt]]));
            freq[arr[rt]] ++;
            st.insert(freq[arr[rt]]);
            rt++;
        }
    }

    cout << ans << endl;
    return 0;
}