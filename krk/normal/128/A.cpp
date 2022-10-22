#include <iostream>
#include <vector>
using namespace std;

const int Maxn = 8;
const int Maxt = 200;
const int Maxd = 9;
const int dy[Maxd] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
const int dx[Maxd] = {0, -1, 0, 1, -1, 1, -1, 0, 1};

vector <int> sr, sc;
int mr, mc, ar, ac;
bool reach[Maxn][Maxn][Maxt];

bool Correct(int r, int c, int t)
{
     for (int i = 0; i < sr.size(); i++)
         if (c == sc[i] && (r == sr[i] + t || r == sr[i] + t + 1)) return false;
     return true;
}

bool canReach(int mr, int mc, int t)
{
     if (mr == ar && mc == ac) return true;
     if (t >= Maxt) return false;
     if (reach[mr][mc][t]) return false;
     reach[mr][mc][t] = true;
     for (int i = 0; i < Maxd; i++) {
         mr += dy[i]; mc += dx[i];
         if (0 <= mr && mr < Maxn && 0 <= mc && mc < Maxn && Correct(mr, mc, t)) 
            if (canReach(mr, mc, t + 1)) return true;
         mr -= dy[i]; mc -= dx[i];
     }
     return false;
}

int main()
{
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++) {
            char c; cin >> c;
            if (c == 'A') { ar = i; ac = j; }
            if (c == 'M') { mr = i; mc = j; }
            if (c == 'S') { sr.push_back(i); sc.push_back(j); }
        }
    if (canReach(mr, mc, 0)) cout << "WIN\n";
    else cout << "LOSE\n";
    return 0;
}