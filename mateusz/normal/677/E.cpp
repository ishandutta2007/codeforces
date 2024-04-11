#include <bits/stdc++.h>

using namespace std;

const int N = 1005, M = 1e9 + 7;

int n;
char board[N][N];
int colSum[N][N][4], rowSum[N][N][4], diagASum[N][N][4], diagBSum[N][N][4];

int getSum(int x, int y, int d, int what, int type) {
    if (type == 0) {
        int _colSum = colSum[x + d - 1][y][what] - colSum[x - d][y][what];
        int _rowSum = rowSum[x][y + d - 1][what] - rowSum[x][y - d][what];
        return _colSum + _rowSum - (board[x][y] == what);
    } else {
        int _diagASum = diagASum[x + d - 1][y + d - 1][what] - diagASum[x - d][y - d][what];
        int _diagBSum = diagBSum[x + d - 1][y - d + 1][what] - diagBSum[x - d][y + d][what];
        return _diagASum + _diagBSum - (board[x][y] == what);
    }
}

bool compare(int twos, int threes) {
    return (long double)twos > (long double)threes / 0.63092975357145743L;
}

bool better(pair<int, int> A, pair<int, int> B) {
    int minTwo = min(A.first, B.first);
    int minThree = min(A.second, B.second);
    A.first -= minTwo;
    A.second -= minThree;
    B.first -= minTwo;
    B.second -= minThree;
    if (A.first == 0 && A.second == 0) {
        return false;
    }
    if (B.first == 0 && B.second == 0) {
        return true;
    }

    if (A.first > 0) {
        return compare(A.first, B.second);
    } else {
        return !compare(B.first, A.second);
    }
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
        for (int j = 1; j <= n; j++) {
            board[i][j] -= 48;
        }
    }
    bool noZero = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= 3; k++) {
                colSum[i][j][k] = colSum[i - 1][j][k] + (board[i][j] == k);
                rowSum[i][j][k] = rowSum[i][j - 1][k] + (board[i][j] == k);
                diagASum[i][j][k] = diagASum[i - 1][j - 1][k] + (board[i][j] == k);
                diagBSum[i][j][k] = diagBSum[i - 1][j + 1][k] + (board[i][j] == k);
                if (board[i][j] != 0) {
                    noZero = true;
                }
            }
        }
    }

    if (noZero == false) {
        printf("0\n");
        return 0;
    }

    int bestRow = 0;
    int bestColumn = 0;
    int bestD = 0;
    int type = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i][j] == 0) {
                continue;
            }
            for (int t = 0; t < 2; t++) {
                int low = 1;
                int high = min(min(i, n - i + 1), min(j, n - j + 1));
                int res = 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (getSum(i, j, mid, 0, t) > 0) {
                        high = mid - 1;
                    } else {
                        res = mid;
                        low = mid + 1;
                    }
                }

                pair<int, int> product = make_pair(getSum(i, j, res, 2, t), getSum(i, j, res, 3, t));
                pair<int, int> bestProduct = make_pair(getSum(bestRow, bestColumn, bestD, 2, type), getSum(bestRow, bestColumn, bestD, 3, type));
                if (better(product, bestProduct)) {
                    bestRow = i;
                    bestColumn = j;
                    bestD = res;
                    type = t;
                }
            }
        }
    }

    int ans = 1;

    pair<int, int> bestProduct = make_pair(getSum(bestRow, bestColumn, bestD, 2, type), getSum(bestRow, bestColumn, bestD, 3, type));

    for (int i = 0; i < bestProduct.first; i++) {
        ans = (long long)ans * 2 % M;
    }
    for (int i = 0; i < bestProduct.second; i++) {
        ans = (long long)ans * 3 % M;
    }

    printf("%d\n", ans);

    return 0;
}