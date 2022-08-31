#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n;
ll a[1200000];
int pr[1200000];
int nx[1200000];
vector<int> st;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);

    st.clear();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] <= a[i])
            st.pop_back();
        if (st.empty())
            pr[i] = -1;
        else
            pr[i] = st.back();
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] < a[i])
            st.pop_back();
        if (st.empty())
            nx[i] = n;
        else
            nx[i] = st.back();
        st.push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * (ll)(i - pr[i]) * (ll)(nx[i] - i);
    }
    st.clear();
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] >= a[i])
            st.pop_back();
        if (st.empty())
            pr[i] = -1;
        else
            pr[i] = st.back();
        st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.back()] > a[i])
            st.pop_back();
        if (st.empty())
            nx[i] = n;
        else
            nx[i] = st.back();
        st.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        ans -= a[i] * (ll)(i - pr[i]) * (ll)(nx[i] - i);
    }
    cout << ans << "\n";
    return 0;
}