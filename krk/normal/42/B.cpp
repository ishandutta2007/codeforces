#include <iostream>
using namespace std;

const int Maxn = 8, Maxm = 9;

int dy[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int board[Maxn][Maxn], swit[Maxn][Maxn];

int main()
{
    char c, d;
    int a[3], b[3], kx, ky;
    for (int i = 0; i < 3; i++) {
        cin >> c >> d;
        a[i] = c - 'a'; b[i] = d - '1';
        board[a[i]][b[i]] = 1 << i;
        swit[a[i]][b[i]] = 1 << i; 
    }
    for (int i = 0; i < 2; i++) {
        for (int j = a[i]-1; j >= 0; j--) {
            board[j][b[i]] |= 1 << i;
            if (swit[j][b[i]]) break;
        }
        for (int j = a[i]+1; j < Maxn; j++) {
            board[j][b[i]] |= 1 << i;
            if (swit[j][b[i]]) break;
        }
        for (int j = b[i]-1; j >= 0; j--) {
            board[a[i]][j] |= 1 << i;
            if (swit[a[i]][j]) break;
        }
        for (int j = b[i]+1; j < Maxn; j++) {
            board[a[i]][j] |= 1 << i;
            if (swit[a[i]][j]) break;
        }
    }
    for (int i = 0; i < Maxm; i++)
       if (0 <= a[2] + dy[i] && a[2] + dy[i] < Maxn && 0 <= b[2] + dx[i] && b[2] + dx[i] < Maxn)
          board[a[2]+dy[i]][b[2]+dx[i]] |= 1 << 2;
    cin >> c >> d;
    kx = c - 'a'; ky = d - '1';
    int i;
    for (i = 0; i < Maxm; i++)
       if (0 <= kx + dy[i] && kx + dy[i] < Maxn && 0 <= ky + dx[i] && ky + dx[i] < Maxn &&
           (board[kx+dy[i]][ky+dx[i]] ^ swit[kx+dy[i]][ky+dx[i]]) == 0) break;
    if (i == Maxm) cout << "CHECKMATE\n";
    else cout << "OTHER\n";
    return 0;
}