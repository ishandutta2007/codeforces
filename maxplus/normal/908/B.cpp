#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 50, D = 4;

char dir[] = "URDL";
string s;
char a[N][N];
int r, c, R, C;

int check() {
    int i = R, j = C;
    for (auto Cmd: s) {
        int cmd = Cmd - '0';
        if (dir[cmd] == 'U')
            --i;
        else if (dir[cmd] == 'R')
            ++j;
        else if (dir[cmd] == 'D')
            ++i;
        else if (dir[cmd] == 'L')
            --j;
        if (i < 0 || j < 0 || i == r || j == c || a[i][j] == '#')
            break;
        if (a[i][j] == 'E')
            return 1;
    }
    return 0;
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'S')
                R = i, C = j;
        }
    cin >> s;
    sort(dir, dir + D);
    int ans = 0;
    do {
        ans += check();
    } while (next_permutation(dir, dir + D));
    cout << ans;
    return 0;
}