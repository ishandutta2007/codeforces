#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int a[nax];
int n;

vector <pair <int, int>> keep ;

void add (int h) {
    vector <pair <int, int>> new_pair;

    for (auto &[x, y] : keep) {
        //new_pair.emplace_back(x + 1, 0);
        new_pair.emplace_back(x + 1, min(y, h));
        if (h <= y) new_pair.emplace_back(x, h);
        if (h > y && x + h - y <= n) new_pair.emplace_back(x + h - y, h);
        if (x + h <= n) new_pair.emplace_back(x + h, h);
    }

    sort(new_pair.begin(), new_pair.end(), [&] (const auto &l, const auto &r){
            return l.first == r.first ? l.second > r.second : l.first < r.first;
        });
    while (!new_pair.empty() && new_pair.back().first > n) {
        new_pair.pop_back();
    }

    new_pair.erase(unique(new_pair.begin(), new_pair.end(), [&] (const auto &l, const auto &r) {
                          return l.first == r.first;
                          }), new_pair.end());

    keep = new_pair;
}

/// sucked O(n^3) passed pretest

int main() {
    scanf("%d", &n);
    //n = 5000;
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d", a + i);
    ///printf("%d\n", solve(1, n, 0));
    keep.emplace_back(0, 0);

    for (int i = 1 ; i <= n ; ++ i)
        add(a[i]);
    printf("%d\n", keep[0].first);
}