#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1000 * 1000 + 13;
const int M = 20 + 1;
const long long INF = 1000 * 1000 * 1000 * 1ll * 1000 * 1000 * 1000;

int n;
long long d[(1 << M)];
long long cnt[M][M];
vector<int> col[M];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        col[x].push_back(i);
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == j) {
                continue;
            }
            if ((int)col[i].size() == 0 || (int)col[j].size() == 0) {
                continue;
            }
            int pos2 = 0;
            for (int pos1 = 0; pos1 < (int)col[i].size(); pos1++) {
                while (true) {
                    if (pos2 == (int)col[j].size() - 1 || col[j][pos2 + 1] > col[i][pos1]) {
                        break;
                    }
                    pos2++;
                }
                if (col[i][pos1] > col[j][pos2]) {
                    cnt[i][j] += pos2 + 1;
                }
            }
        }
    }

    for (int mask = 0; mask < (1 << 20); mask++) {
        d[mask] = INF;
    }
    d[0] = 0;
    for (int mask = 0; mask < (1 << 20); mask++) {
        vector<int> was;
        for (int i = 0; i < 20; i++) {
            if (mask & (1 << i)) {
                was.push_back(i);
            }
        }
        for (int i = 0; i < 20; i++) {
            if (mask & (1 << i)) {
                continue;
            }
            long long sum = 0;
            for (int j = 0; j < (int)was.size(); j++) {
                sum += cnt[was[j]][i];
            }
            int nmask = mask | (1 << i);
            d[nmask] = min(d[nmask], d[mask] + sum);
        }
    }
    cout << d[(1 << 20) - 1] << endl;
}