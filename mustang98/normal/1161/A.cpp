#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int n, k;
int x[max_n];

int ans = 0;
set<int> st;
int fst[max_n];
int lst[max_n];

bool check(int s, int f) {
    if (s == f) {
        if (st.find(s) == st.end()) {
            return true;
        } else {
            return false;
        }
    }
    if (fst[s] == -1 || fst[f] == -1) return true;
    if (fst[s] < lst[f]) {
        return false;
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < max_n; ++i) {
        fst[i] = -1;
        lst[i] = -1;
    }
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int pos;
        cin >> pos;
        --pos;
        x[i] = pos;
        st.insert(x[i]);
        if (fst[pos] == -1) {
            fst[pos] = i;
        }
        lst[pos] = i;
    }
    for (int i = 0; i < n; ++i) {
        ans += check(i, i);
        if (i + 1 < n) {
            ans += check(i, i + 1);
        }
        if (i - 1 >= 0) {
            ans += check(i, i - 1);
        }
    }
    cout << ans << endl;
    return 0;
}