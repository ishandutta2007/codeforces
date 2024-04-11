#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int ask(int i) {
    cout << "? " << i  + 1 << endl;
    int res;
    cin >> res;
    return res - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<char> visited(n);
        int k = 0;
        VI st;
        VI p(n);
        rep(i, n) if (!visited[i]) {
            st.clear();
            int j = ask(i);
            k++;
            do {
                st.emplace_back(j);
                j = ask(i);
                k++;
            } while (j != st[0]);
            int l = st.size();
            int d = k - 1 - l;
            rotate(st.begin(), st.begin() + (-d % l + l) % l, st.end());
            assert(st[0] == i);
            st.emplace_back(i);
            rep(j, l) {
                int u = st[j], v = st[j + 1];
                p[u] = v;
                visited[u] = true;
            }
        }
        cout << "!";
        rep(i, n) cout << ' ' << p[i] + 1;
        cout << endl;
    }
}