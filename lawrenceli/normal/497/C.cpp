#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<piii, int> piiii;

const int MAXN = 100100;

int n, m;
piii notes[MAXN];
piiii act[MAXN];
int ans[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> notes[i].fi.fi >> notes[i].fi.se;
        notes[i].se = i;
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> act[i].fi.fi.fi >> act[i].fi.fi.se >> act[i].fi.se;
        act[i].se = i;
    }

    sort(notes, notes+n);
    sort(act, act+m);

    set<piii> st;
    for (int i=0, j=0; i<n; i++) {
        while (j<m && act[j].fi.fi.fi <= notes[i].fi.fi) {
            st.insert(piii(pii(act[j].fi.fi.se, act[j].fi.se), act[j].se));
            j++;
        }
        typeof(st.begin()) it = st.lower_bound(piii(pii(notes[i].fi.se, -1), -1));
        if (it == st.end()) {
            cout << "NO\n";
            return 0;
        } else {
            piii p = *it;
            st.erase(it);
            ans[notes[i].se] = p.se+1;
            if (p.fi.se > 1) st.insert(piii(pii(p.fi.fi, p.fi.se-1), p.se));
        }
    }

    cout << "YES\n";
    for (int i=0; i<n; i++)
        cout << ans[i] << ' ';
    return 0;
}