
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    set<pii> se1, se2;
    int idx = 0;
    while(q--) {
        int ty;
        cin >> ty;
        if(ty == 1) {
            int m;
            cin >> m;
            idx++;
            se1.insert({idx, -m});
            se2.insert({-m, idx});
        }else if(ty == 2) {
            auto pa = *se1.begin();
            se1.erase(se1.begin());
            se2.erase(se2.find({pa.second, pa.first}));
            cout << pa.first << ' ';
        }else {
            auto pa = *se2.begin();
            se2.erase(se2.begin());
            se1.erase(se1.find({pa.second, pa.first}));
            cout << pa.second << ' ';
        }
    }
    cout << '\n';
}