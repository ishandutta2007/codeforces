//
//  main.cpp
//  Contests
//
//  Created by Roman Rubanenko on 3/5/17.
//  Copyright  2017 Roman Rubanenko. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

constexpr int MAX_N = 1024;

constexpr int INF = 1011000111;

int dist[MAX_N][MAX_N];

tuple<char, int, int> TURNS[4] = {
    {'D',  1,  0},
    {'L',  0, -1},
    {'R',  0,  1},
    {'U', -1,  0},
};


int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            dist[i][j] = INF;//obstacle
        }
    }
    int n, m, k;
    cin >> n >> m >> k;
    int startX = 0, startY = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            const char c = s[j - 1];
            if (c == 'X') {
                startX = i;
                startY = j;
            }
            if (c != '*') {
                dist[i][j] = -1;//valid, but unused yet
            }
        }
    }
    deque<pair<int, int>> q;
    q.push_front({startX, startY});
    dist[startX][startY] = 0;
    int cellsCanReach = 0;
    while (!q.empty()) {
        cellsCanReach++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();
        for (const auto& t : TURNS) {
            int nx = x + get<1>(t);
            int ny = y + get<2>(t);
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push_back({nx, ny});
            }
        }
    }
    if (cellsCanReach == 1 || k % 2 == 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int x = startX, y = startY;
    string ans = "";
    while (k--) {
        for (const auto& t : TURNS) {
            int nx = x + get<1>(t);
            int ny = y + get<2>(t);
            if (dist[nx][ny] <= k) {
                ans += get<0>(t);
                x = nx;
                y = ny;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}