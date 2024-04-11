#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxd = 9;
const string dirs[Maxd] = {"Right", "Left", "Up", "Down", "Down-Right", "Down-Left", "Up-Left", "Up-Right", "Done"};
const int dr[Maxd] = {0, 0, -1, 1, 1, 1, -1, -1, 0};
const int dc[Maxd] = {1, -1, 0, 0, 1, -1, -1, 1, 0};

int T;
int R, C;

ii Get()
{
    string s; cin >> s;
    for (int i = 0; i < Maxd; i++)
        if (s == dirs[i]) return ii(dr[i], dc[i]);
    return ii(-1, -1);
}

void Go(int r, int c)
{
    printf("%d %d\n", r + 1, c + 1);
    R = r, C = c;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        Go(0, 0);
        if (Get() == ii(0, 0)) continue;
        Go(1, 0);
        bool dwn = true;
        while (true) {
            ii wh = Get();
            if (wh == ii(0, 0)) break;
            if (wh.second == 1) {
                Go(R, C + 1);
                if (R != 1) {
                    wh = Get();
                    if (wh == ii(0, 0)) break;
                    Go(1, C);
                }
                dwn = true;
            } else if (wh.second == -1) {
                if (R != 1) {
                    Go(1, C);
                    dwn = true;
                } else {
                    Go(6, C);
                    dwn = false;
                }
            } else if (R == 1 && !dwn) {
                Go(R, C + 1);
                dwn = true;
            } else if (R == 6 && dwn) {
                Go(R, C + 1);
                dwn = false;
            } else if (dwn)
                Go(R + 1, C);
            else Go(R - 1, C);
        }
    }
    return 0;
}