
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s;

// dist[i][j][x][y] = distance between digit i and digit k using only x and y.
int dist[10][10][10][10];
// number of jumps from digit i to digit j in string s.
int jumps[10][10];
int cost[10][10];

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    for(int i = 1; i < s.length(); i++) {
        jumps[s[i - 1] - '0'][s[i] - '0']++;
    }
    for(int x = 0; x < 10; x++) {
        for(int y = 0; y < 10; y++) {
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < 10; j++) {
                    dist[i][j][x][y] = -1;
                }
            }
            for(int i = 0; i < 10; i++) {
                dist[i][(i + x) % 10][x][y] = 1;
                dist[i][(i + y) % 10][x][y] = 1;
                // dist[i][i][x][y] = 0;
            }
            for(int k = 0; k < 10; k++) {
                for(int i = 0; i < 10; i++) {
                    for(int j = 0; j < 10; j++) {
                        if(dist[i][k][x][y] >= 0 && dist[k][j][x][y] >= 0 && 
                                (dist[i][k][x][y] + dist[k][j][x][y] < dist[i][j][x][y] || dist[i][j][x][y] < 0)) {
                            dist[i][j][x][y] = dist[i][k][x][y] + dist[k][j][x][y];
                        }
                    }
                }
            }
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < 10; j++) {
                    if(jumps[i][j] > 0 && cost[x][y] >= 0) {
                        if(dist[i][j][x][y] >= 0)
                            cost[x][y] += jumps[i][j] * (dist[i][j][x][y] - 1);
                        else
                            cost[x][y] = -1;
                    }
                }
            }
            cout << cost[x][y] << " ";
        }
        cout << endl;
    }
}