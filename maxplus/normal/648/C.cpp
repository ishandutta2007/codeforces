#define first f
#define second s
#include <iostream>
#include <map>

using namespace std;

int n, m, r, c;
char a[111][111];
pair<int, int> d[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
map<pair<int, int>, char> dir;

int main()
{
    dir[d[0]] = 'U';
    dir[d[1]] = 'D';
    dir[d[2]] = 'L';
    dir[d[3]] = 'R';
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
        cin >> a[i][j], a[i][j] == 'S'? (r = i, c = j): 0;
    while (1)
    {
        for (auto d: ::d)
            if (a[r + d.f][c + d.s] == '*')
                {cout << dir[d], a[r][c] ^= '*', r += d.f, c += d.s;goto end_cyc;}
        for (auto d: ::d)
            if (a[r + d.f][c + d.s] == ('*' ^ 'S'))
                {cout << dir[d], a[r][c] ^= '*', r += d.f, c += d.s;break;}
        break;
        end_cyc:;
    }
    return 0;
}