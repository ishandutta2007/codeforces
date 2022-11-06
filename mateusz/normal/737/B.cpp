#include <bits/stdc++.h>

using namespace std;

const int N = 200005, INF = 2e9;

int n, a, b, k;
char state[N];

int main() {

    scanf("%d %d %d %d", &n, &a, &b, &k);

    int freeCells = n - k;
    int last = 0;
    scanf("%s", &state[1]);
    for (int i = 1; i <= n; i++) {
        state[i] -= 48;
        if (state[i] == 1) {
            freeCells -= (i - last - 1) % b;
            last = i;
        }
    }
    freeCells -= (n + 1 - last - 1) % b;

    int totalCells = a * b;
    vector<int> cells;
    int cons = 0;
    for (int i = 1; i <= n; i++) {
        if (state[i] == 1) {
            cons = 0;
            continue;
        }
        cons++;
        if (cons == b) {
            cells.push_back(i);
            cons = 0;
            freeCells -= b;
            if (freeCells < totalCells) {
                break;
            }
        }
    }

    printf("%d\n", cells.size());
    for (int i = 0; i < cells.size(); i++) {
        printf("%d ", cells[i]);
    }

    return 0;
}