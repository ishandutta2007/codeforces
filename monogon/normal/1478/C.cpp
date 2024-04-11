
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
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        vector<ll> what;
        bool ok = true;
        rep(i, 0, 2 * n) {
            ll d;
            cin >> d;
            if(d % 2 != 0) ok = false;
            what.push_back(d);
        }
        sort(all(what));
        ll wtf = 0, ugh = 0;
        rep(i, 0, n) {
            if(what[2 * i] != what[2 * i + 1]) ok = false;
            if(i > 0) {
                ll dif = what[2 * i] - what[2 * (i - 1)];
                if(dif == 0 || dif % (2LL * i) != 0) {
                    ok = false;
                }
                ugh += (dif / (2LL * i));
                wtf += ugh;
            }
        }
        ll aaaaaaaaaaaaaaaaaaaa = (what[0] - 2LL * wtf);
        if(aaaaaaaaaaaaaaaaaaaa <= 0 || aaaaaaaaaaaaaaaaaaaa % (2 * n) != 0) ok = false;
        cout << (ok ? "YES" : "NO") << '\n';
    }
}