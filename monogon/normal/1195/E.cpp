
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 3005;
int n, m, a, b;
ll g0, x, y, z;
ll arr[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> a >> b >> g0 >> x >> y >> z;
    ll g = g0;
    deque<pair<int, ll> > Q;
    for(int i = 0; i < n; i++) {
        Q.clear();
        int j;
        for(j = 0; j < b; j++) {
            while(!Q.empty() && g <= Q.back().second) {
                Q.pop_back();
            }
            Q.push_back(make_pair(j, g));
            g = (g * x + y) % z;
        }
        for(; j < m; j++) {
            arr[i][j - b] = Q.front().second;
            while(!Q.empty() && Q.front().first <= j - b) {
                Q.pop_front();
            }
            while(!Q.empty() && g <= Q.back().second) {
                Q.pop_back();
            }
            Q.push_back(make_pair(j, g));
            g = (g * x + y) % z;
        }
        arr[i][m - b] = Q.front().second;
    }
    deque<int> Q2;
    ll tot = 0;
    for(int j = 0; j <= m - b; j++) {
        Q2.clear();
        int i;
        for(i = 0; i < a; i++) {
            while(!Q2.empty() && arr[i][j] <= arr[Q2.back()][j]) {
                Q2.pop_back();
            }
            Q2.push_back(i);
        }
        for(; i < n; i++) {
            tot += arr[Q2.front()][j];
            while(!Q2.empty() && Q2.front() <= i - a) {
                Q2.pop_front();
            }
            while(!Q2.empty() && arr[i][j] <= arr[Q2.back()][j]) {
                Q2.pop_back();
            }
            Q2.push_back(i);
        }
        tot += arr[Q2.front()][j];
    }
    cout << tot << endl;
}