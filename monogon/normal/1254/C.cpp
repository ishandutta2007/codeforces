
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// Make a line between points 1 and 2.
// The sign of cross product a_1 a_2 x a_1 a_k tells
// which side of the line a_1 a_2, a_k lies on.
// split the points by which side of the line.
// On each side of the line, area of triangle a_1 a_2 a_k
// tells distance from a_k to line a_1 a_2. Store these areas.
// Find point of farthest distance on each side of the line.
// Partition the points by which side of line.
// In each of the 4 quadrants, sort the points by
// distance from a_1 a_2 appropriately.

const int N = 1005;
int n, s;
bool side1[N], side2[N];
int best[2];
ll area[N];
vector<pair<ll, int>> v[2][2];

ll c;

ll queryarea(int i, int j, int k) {
    cout << "1 " << i << " " << j << " " << k << endl;
    cin >> c;
    return c;
}
int querysign(int i, int j, int k) {
    cout << "2 " << i << " " << j << " " << k << endl;
    cin >> c;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 3; i <= n; i++) {
        s = querysign(1, 2, i);
        side1[i] = (s > 0);
        area[i] = queryarea(1, 2, i);
        if(area[best[side1[i]]] <= area[i]) {
            best[side1[i]] = i;
        }
    }
    for(int i = 3; i <= n; i++) {
        if(i != best[side1[i]]) {
            s = querysign(1, best[side1[i]], i);
            side2[i] = (s > 0);
            v[side1[i]][side2[i]].emplace_back(area[i], i);
        }
    }
    for(int i : {0, 1}) {
        sort(v[i][0].begin(), v[i][0].end());
        sort(v[i][1].rbegin(), v[i][1].rend());
    }
    cout << "0 1";
    for(auto p : v[0][0]) {
        cout << " " << p.second;
    }
    if(best[0] > 0) {
        cout << " " << best[0];
    }
    for(auto p : v[0][1]) {
        cout << " " << p.second;
    }
    cout << " 2";
    for(auto p : v[1][0]) {
        cout << " " << p.second;
    }
    if(best[1] > 0) {
        cout << " " << best[1];
    }
    for(auto p : v[1][1]) {
        cout << " " << p.second;
    }
    cout << endl;
}