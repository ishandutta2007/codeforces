
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5;
int n;
int perm[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    stack<pii> st;
    stack<int> ind;
    int idx = 1;
    rep(i, 0, 2 * n) {
        char c;
        cin >> c;
        if(c == '+') {
            st.emplace(1, 1);
            ind.push(idx);
            idx++;
        }else {
            int p;
            cin >> p;
            if(st.empty() || st.top().first > p) {
                cout << "NO\n";
                return 0;
            }
            perm[ind.top()] = p;
            ind.pop();
            int pr, amt;
            tie(pr, amt) = st.top(); st.pop();
            st.emplace(p, amt - 1);
            while(sz(st) >= 2) {
                tie(pr, amt) = st.top(); st.pop();
                if(st.top().first <= pr) {
                    int pr2, amt2;
                    tie(pr2, amt2) = st.top();
                    st.pop();
                    st.emplace(pr, amt + amt2);
                }else {
                    st.emplace(pr, amt);
                    break;
                }
            }
            if(st.top().second == 0) st.pop();
        }
    }
    cout << "YES\n";
    rep(i, 1, n + 1) {
        cout << perm[i] << ' ';
    }
    cout << '\n';
}