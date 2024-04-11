#include <iostream>
#include <string>
using namespace std;

int dd, mm, yy, bd, bm, by;

int Days(int m, int y)
{
    if (m == 2) if (y % 4) return 28;
                else return 29;
    else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    else return 31;
}

bool E(int d, int m, int y)
{
     if (m > 12) return false;
     if (d > Days(m, y)) return false;
     int dy = yy - y;
     if (m > mm || m == mm && d > dd) dy--;
     return dy >= 18;
}

int main()
{
    string a, b;
    cin >> a;
    dd = (a[0] - '0') * 10 + (a[1] - '0');
    mm = (a[3] - '0') * 10 + (a[4] - '0');
    yy = (a[6] - '0') * 10 + (a[7] - '0');
    cin >> b;
    bd = (b[0] - '0') * 10 + (b[1] - '0');
    bm = (b[3] - '0') * 10 + (b[4] - '0');
    by = (b[6] - '0') * 10 + (b[7] - '0');
    if (E(bd, bm, by) || E(bd, by, bm) || E(bm, bd, by) ||
        E(bm, by, bd) || E(by, bd, bm) || E(by, bm, bd)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}