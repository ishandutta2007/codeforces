#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define fi first
#define se second

const int MAXN = 100100;

int n, a[MAXN];
string ans[MAXN];

typedef pair<int, int> pii;
struct cmp {
    bool operator()(const pii& p1, const pii& p2) const {
        return p1.fi != p2.fi ? p1.fi > p2.fi : p1.se < p2.se;
    }
};
set<pii, cmp> st;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n;
    for (int i=0; i<n; i++) ans[i] = "pushStack";
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            if  (st.size() == 0) ans[i] = "0";
            else if (st.size() == 1) {
                ans[i-1] = "pushStack";
                ans[i] = "1 popStack";
            } else if (st.size() == 2) {
                ans[i-2] = "pushStack";
                ans[i-1] = "pushQueue";
                ans[i] = "2 popStack popQueue";
            } else {
                typeof(st.begin()) it = st.begin();
                pii p1 = *it; it++; pii p2 = *it; it++; pii p3 = *it;
                for (int j=i-st.size(); j<i; j++) {
                    ans[j] = "pushFront";
                }
                ans[p1.se] = "pushStack";
                ans[p2.se] = "pushQueue";
                ans[p3.se] = "pushBack";
                ans[i] = "3 popStack popQueue popBack";
            }
            st.clear();
        } else st.insert(pii(a[i], i));
    }
    for (int i=0; i<n; i++) cout << ans[i] << endl;
    return 0;
}