
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
ll s[N], a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, S;
    cin >> n >> S;
    ll p1 = 0, p2 = 0;
    ll happy = 0;
    vector<pair<ll, int>> ve1, ve2;
    rep(i, 0, n) {
        cin >> s[i] >> a[i] >> b[i];
        if(a[i] < b[i]) {
            ve1.emplace_back(a[i] - b[i], s[i]);
            p2 += s[i];
        }else {
            ve2.emplace_back(b[i] - a[i], s[i]);
            p1 += s[i];
        }
        happy += max(a[i], b[i]) * s[i];
    }
    sort(ve1.rbegin(), ve1.rend());
    sort(ve2.rbegin(), ve2.rend());
    // cout << "---" << endl;
    // for(auto &pa : ve1) {
    //     cout << pa.first << ' ' << pa.second << endl;
    // }
    // cout << "---" << endl;
    // for(auto &pa : ve2) {
    //     cout << pa.first << ' ' << pa.second << endl;
    // }
    // cout << "happy = " << happy << endl;
    
    // if(p1 % S == 0 || p2 % S == 0) {
    //     cout << happy << '\n';
    //     return 0;
    // }
    if((p1 % S) + (p2 % S) <= S) {
        // cout << "woah" << endl;
        ll happy1 = happy, happy2 = happy;
        happy = 0;
        // take S - (p1 % S) from ve1
        ll amt = p2 % S;
        if(p2 >= amt) {
            for(auto &pa : ve1) {
                ll dif = min((ll) pa.second, amt);
                amt -= dif;
                happy1 += pa.first * dif;
            }
            happy = max(happy, happy1);
            // cout << "happy1 = " << happy1 << endl;
        }
        // or take S - (p2 % S) from ve2
        amt = p1 % S;
        if(p1 >= amt) {
            for(auto &pa : ve2) {
                ll dif = min((ll) pa.second, amt);
                amt -= dif;
                happy2 += pa.first * dif;
            }
            happy = max(happy, happy2);
            // cout << "happy2 = " << happy2 << endl;
        }
    }
    cout << happy << '\n';
}