
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll x, y, bx, by, xs, ys, t;
int ax, ay;
vector<pair<ll, ll>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y >> ax >> ay >> bx >> by >> xs >> ys >> t;
    do {
        v.emplace_back(x, y);
        x = ax * x + bx;
        y = ay * y + by;
    }while(x <= xs + t && y <= ys + t);

    int n = v.size();
    int best = 0;
    for(int i = 0; i < n; i++) {
        tie(x, y) = v[i];
        ll d = abs(x - xs) + abs(y - ys);
        if(d <= t && best < 1) best = 1;
        for(int j = i + 1; j < n; j++) {
            d += abs(v[j].first - x) + abs(v[j].second - y);
            if(d <= t && j - i + 1 > best) best = j - i + 1;
            tie(x, y) = v[j];
        }
        tie(x, y) = v[i];
        d = abs(x - xs) + abs(y - ys);
        for(int j = i - 1; j >= 0; j--) {
            d += abs(v[j].first - x) + abs(v[j].second - y);
            if(d <= t && i - j + 1 > best) best = i - j + 1;
            tie(x, y) = v[j];
        }
    }
    cout << best << endl;
}