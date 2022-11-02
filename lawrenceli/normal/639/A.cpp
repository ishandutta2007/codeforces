#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 150100;

int N, K, Q;
int t[maxn];

int main() {
    cin >> N >> K >> Q;
    for (int i = 0; i < N; i++) cin >> t[i];

    set<pair<int, int> > st;
    for (int i = 0; i < Q; i++) {
        int qt, id;
        cin >> qt >> id;
        id--;
        if (qt == 1) {
            st.insert(MP(t[id], id));
            if (st.size() > K) st.erase(st.begin());
        } else {
            bool b = 0;
            for (auto it : st)
                if (it.B == id) {
                    cout << "YES\n";
                    b = 1;
                    break;
                }

            if (!b) cout << "NO\n";
        }
    }
}