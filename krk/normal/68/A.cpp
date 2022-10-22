#include <iostream>
using namespace std;

int p[4], a, b, ans, x, sat, gen[4];
bool was[4];

void Gen(int lvl)
{
     if (lvl == 4) {
             if (x % p[gen[0]] % p[gen[1]] % p[gen[2]] % p[gen[3]] == x) sat++;
     } else 
          for (int i = 0; i < 4; i++) if (!was[i]) {
              was[i] = true; gen[lvl] = i;
              Gen(lvl + 1);
              was[i] = false;
          }
}

int main()
{
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
    for (x = a; x <= b; x++) {
        sat = 0;
        Gen(0);
        if (sat >= 7) ans++;
    }
    cout << ans << endl;
    return 0;
}