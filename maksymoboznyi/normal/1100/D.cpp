#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e3 + 5;

int is[N][N], x, y, dx, dy;
vector<pair<int, int> > pos;

int main()
{
    cin >> x >> y;
    for (int i = 0; i < 666; i++) {
        int x, y;
        cin >> x >> y;
        pos.pb({x, y});
        is[x][y] = 1;
    }
    int state = 0;
    while (1) {
        if (state == 0) {
            dx = dy = 0;
            if (x > 500)
                dx = -1;
            else if (x < 500)
                dx = 1;
            if (y > 500)
                dy = -1;
            else if (y < 500)
                dy = 1;
        }
        if (dx == 0 && dy == 0) {
            state = 1;
            int c1=0, c2=0, c3=0, c4=0;
            for (int i = 1; i <= 500; i++)
                for (int j = 1; j <= 500; j++)
                    c1 += is[i][j];
            for (int i = 501; i <= 999; i++)
                for (int j = 1; j <= 500; j++)
                    c3 += is[i][j];
            for (int i = 1; i <= 500; i++)
                for (int j = 501; j <= 999; j++)
                    c2 += is[i][j];
            for (int i = 501; i <= 999; i++)
                for (int j = 501; j <= 999; j++)
                    c4 += is[i][j];
            int cmax = min(min(c1, c2), min(c3, c4));
            if (cmax == c1)
                dx = 1, dy = 1;
            if (cmax == c2)
                dx = 1, dy = -1;
            if (cmax == c3)
                dx = -1, dy = 1;
            if (cmax == c4)
                dx = -1, dy = -1;
        }
        if (x + dx < 1 || x + dx > 999)
            dx = 0;
        if (y + dy < 1 || y + dy > 999)
            dy = 0;
        if (is[x + dx][y + dy]) {
            cout << x + dx << ' ' << y << endl, x += dx;
            cout.flush();
            return 0;
        } else
            cout << x + dx << ' ' << y + dy << endl, cout.flush(), x += dx, y += dy;
        for (int i = 0; i < pos.size(); i++)
            if (pos[i].first == x || pos[i].second == y)
            {
                return 0;
            }
        int k, xx, yy;
        cin >> k >> xx >> yy;
        if (k == -1)
            return 0;
        k--;
        is[pos[k].first][pos[k].second] = 0;
        pos[k] = {xx, yy};
        is[xx][yy] = 1;
    }
    return 0;
}