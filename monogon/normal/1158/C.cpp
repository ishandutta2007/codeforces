
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// If next[i] = j, then for all k in [i, j - 1], next[k] <= j
// so, when we read a next value, it creates an upper bound on
// next values, until we may pop it at index j
// push i to ve[next[i]]
// when processing i, assign everything in ve[i] to next available element

// if -1, don't push to ve[], just immediately assign it

// set the first -1 to n. Say at index j.
// ensure that everything to the left has next <= j, everything after we don't care about

const int N = 5e5 + 5;
int t, n, nxt[N], p[N];
vi ve[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 1, n + 1) {
            cin >> nxt[i];
            ve[i].clear();
        }
        ve[n + 1].clear();
        stack<int> st;
        int cnt = 1;
        rep(i, 1, n + 2) {
            while(!ve[i].empty()) {
                p[ve[i].back()] = cnt++;
                ve[i].pop_back();
            }
            if(i == n + 1) break;
            if(!st.empty() && st.top() == i) {
                st.pop();
            }
            if(nxt[i] == -1) {
                p[i] = cnt++;
            }else if(st.empty() || nxt[i] <= st.top()) {
                ve[nxt[i]].push_back(i);
                if(st.empty() || nxt[i] < st.top()) {
                    st.push(nxt[i]);
                }
            }else {
                cout << "-1\n";
                goto lab1;
            }
        }
        rep(i, 1, n + 1) {
            cout << p[i] << ' ';
        }
        cout << '\n';
        lab1:;
    }
}