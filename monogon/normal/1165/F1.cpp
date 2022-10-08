
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

const int N = 2e5 + 5;
int n, m;
int k[N], korig[N];
vi ma[2 * N + 6];
int sum = 0;

bool check(int days) {
    // int money = 0;
    // if(sum == 0) {
    //     cout << 0 << '\n';
    //     return 0;
    // }
    // vi amt(n + 1, 0);
    // rep(day, 1, days + 1) {
    //     for(int x : ma[day]) {
    //         amt[x]++;
    //     }
    // }
    // rep(i, 1, n + 1) k[i] = korig[i];
    // int temp = sum;
    // for(int day = 1; day <= days; day++) {
    //     money++;
    //     for(int x : ma[day]) {
    //         if(amt[x] <= k[x] && k[x] > 0 && money > 0) {
    //             k[x]--;
    //             money--;
    //             temp--;
    //         }
    //         amt[x]--;
    //     }
    // }
    // return 2 * temp <= money;

    int temp = sum;
    int money = days, spent = 0;
    rep(i, 1, n + 1) k[i] = korig[i];
    for(int day = days; day >= 1; day--) {
        money = min(money, day);
        for(int x : ma[day]) {
            while(k[x] > 0 && money > 0) {
                k[x]--;
                temp--;
                money--;
                spent++;
            }
        }
    }
    return temp * 2 <= days - spent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n + 1) {
        cin >> k[i];
        korig[i] = k[i];
        sum += k[i];
    }
    rep(i, 0, m) {
        int d, t;
        cin >> d >> t;
        ma[d].push_back(t);
    }
    if(sum == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int L = 0, R = 2 * N + 5;
    while(L < R) {
        int m = (L + R) / 2;
        if(check(m)) {
            R = m;
        }else {
            L = m + 1;
        }
    }
    cout << L << '\n';

    // int money = 0;
    // if(sum == 0) {
    //     cout << 0 << '\n';
    //     return 0;
    // }
    // for(int day = 1; day <= 2 * N + 5; day++) {
    //     money++;
    //     for(int x : ma[day]) {
    //         while(k[x] > 0 && money > 0) {
    //             k[x]--;
    //             money--;
    //             sum--;
    //         }
    //     }
    //     if(2 * sum <= money) {
    //         cout << day << '\n';
    //         return 0;
    //     }
    // }
    // assert(false);
}