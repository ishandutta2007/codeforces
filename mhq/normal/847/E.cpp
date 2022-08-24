#include <bits/stdc++.h>

using namespace std;

vector<int> ind1, ind2;

int get_dist(int x, int y1, int y2) {
    int d1 = abs(ind1[x] - ind2[y1]) + abs(ind2[y1] - ind2[y2]);
    int d2 = abs(ind1[x] - ind2[y2]) + abs(ind2[y1] - ind2[y2]);
    return min(d1, d2);
}

bool f(int T) {
    int i = 0, j = 0;
    while (i < ind1.size() && j < ind2.size()) {
        if (abs(ind1[i] - ind2[j]) > T) {
            ++i;
        } else {
            int st = j;
            while (j < ind2.size() && get_dist(i, st, j) <= T) ++j;
            ++i;
        }
    }
    return (j == ind2.size());
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') ind2.push_back(i + 1); else
        if (s[i] == 'P') ind1.push_back(i + 1); else continue;
    }
    int l = 1, r = n * 3;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f(mid)) r = mid; else l = mid;
    }
    if (f(l)) cout << l << endl; else cout << r << endl;
    return 0;
}