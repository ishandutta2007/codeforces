#include <bits/stdc++.h>
using namespace std;
bool check (int l, int r, int x) {
    if (l <= x && x <= r) return true;
    return false;
}
int z[4];
int main() {
 int h, m, s, t1, t2;
 cin >> h >> m >> s >> t1 >> t2;
 h = h % 12;
 t1 = t1 % 12;
 t2 = t2 % 12;
 z[0] = 3600 * h + 60 * m  + s;
 z[1] = m * 720 + 12 * s;
 z[2] = s * 720;
 t1 = t1 * 3600;
 t2 = t2 * 3600;
 sort(z, z + 3);
 //cout << t1 << " " << t2 << " " << z[0] << " " << z[1] << " " << z[2] << '\n';
 if (check(z[0], z[1], t1) && check(z[0], z[1], t2)) cout << "YES";
 else if (check(z[1], z[2], t1) && check(z[1], z[2], t2)) cout << "YES";
 else if ((check(z[2], 43200, t1) || check(0, z[0], t1)) && (check(0, z[0], t2) || check(z[2], 43200, t2))) cout << "YES";
 else cout << "NO";
 return 0;
}