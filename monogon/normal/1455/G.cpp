
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

struct node {
    map<int, ll> cost;
    multiset<ll> se;
    ll off = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    vector<node*> st;
    node *X = new node;
    X->cost[0] = 0;
    X->se.insert(0);
    st.push_back(X);
    rep(i, 0, n) {
        string op;
        cin >> op;
        if(op == "set") {
            int y;
            ll v;
            cin >> y >> v;
            node *X = st.back();
            X->off += v;
            if(!X->se.empty() && y != s) {
                ll c = *X->se.begin() - v;
                if(X->cost.count(y)) X->se.erase(X->se.find(X->cost[y]));
                X->cost[y] = c;
                X->se.insert(X->cost[y]);
            }
        }else if(op == "if") {
            int y;
            cin >> y;
            node *X = st.back();
            node *Y = new node;
            if(X->cost.count(y)) {
                Y->cost[y] = X->cost[y] + X->off;
                Y->se.insert(Y->cost[y]);
                X->se.erase(X->se.find(X->cost[y]));
                X->cost.erase(y);
            }
            st.push_back(Y);
        }else if(op == "end") {
            node *X = st.back();
            st.pop_back();
            node *Y = st.back();
            st.pop_back();
            if(sz(X->cost) > sz(Y->cost)) swap(X, Y);
            // X into Y
            for(auto &pa : X->cost) {
                int y; ll c;
                tie(y, c) = pa;
                c += X->off - Y->off;
                if(Y->cost.count(y)) {
                    if(c < Y->cost[y]) {
                        Y->se.erase(Y->se.find(Y->cost[y]));
                        Y->cost[y] = c;
                        Y->se.insert(c);
                    }
                }else {
                    Y->cost[y] = c;
                    Y->se.insert(c);
                }
            }
            st.push_back(Y);
        }
    }
    X = st.back();
    assert(!X->se.empty());
    cout << *X->se.begin() + X->off << '\n';
}