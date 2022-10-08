
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

// each friend has a subset of ingredients, and likes a pizza that is a superset
// There are only 2^9 types of pizzas / preferences. Count the number of 
// pizzas and preferences of each of 512 types
// try each pair of types of pizzas, check against all people
// O(n + m + (2^9)^3) time

int n, m, f, b, pref[1 << 9], cnt[1 << 9], c;
vector<pii> price[1 << 9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while(n--) {
        cin >> f;
        int pizza = 0;
        while(f--) {
            cin >> b;
            pizza ^= (1 << (b - 1));
        }
        pref[pizza]++;
    }
    rep(i, 1, m + 1) {
        cin >> c;
        int pizza = 0;
        cin >> f;
        while(f--) {
            cin >> b;
            pizza ^= (1 << (b - 1));
        }
        cnt[pizza]++;
        price[pizza].emplace_back(c, i);
    }
    rep(i, 0, 1 << 9) {
        sort(all(price[i]));
    }
    int x = 1, y = 2, bestamt = -1, bestprice = INT_MAX;
    auto check = [&](int p1, int p2) -> int {
        int num = 0;
        rep(i, 0, 1 << 9) {
            if((i & (p1 | p2)) == i) {
                num += pref[i];
            }
        }
        return num;
    };
    rep(i, 0, 1 << 9) {
        if(cnt[i] >= 2) {
            int amt = check(i, i);
            if(pair(amt, -price[i][0].fi - price[i][1].fi) > pair(bestamt, -bestprice)) {
                bestamt = amt;
                bestprice = price[i][0].fi + price[i][1].fi;
                x = price[i][0].se;
                y = price[i][1].se;
            }
        }
        rep(j, i + 1, 1 << 9) {
            if(cnt[i] >= 1 && cnt[j] >= 1) {
                int amt = check(i, j);
                if(pair(amt, -price[i][0].fi - price[j][0].fi) > pair(bestamt, -bestprice)) {
                    bestamt = amt;
                    bestprice = price[i][0].fi + price[j][0].fi;
                    x = price[i][0].se;
                    y = price[j][0].se;
                }
            }
        }
    }
    cout << x << ' ' << y << '\n';
}