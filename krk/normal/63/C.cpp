#include <iostream>
using namespace std;

const int Maxn = 10;

int n, nums[Maxn], bulls[Maxn], cows[Maxn], ans, gen[4], saved[4];
bool taken[Maxn];

bool Correct(int wh)
{
     int n = nums[wh], b = 0, c = 0;
     for (int i = 3; i >= 0; i--, n /= 10) {
         int md = n % 10;
         if (md == gen[i]) b++;
         if (taken[md]) c++;
     }
     c -= b;
     return b == bulls[wh] && c == cows[wh];
}

void Gen(int lvl)
{
     if (lvl == 4) {
             int i;
             for (i = 0; i < n; i++) if (!Correct(i)) return;
             ans++;
             for (i = 0; i < 4; i++) saved[i] = gen[i];
     } else for (int i = 0; i < Maxn; i++) if (!taken[i]) {
               taken[i] = true;
               gen[lvl] = i;
               Gen(lvl+1);
               taken[i] = false;
            }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
       cin >> nums[i] >> bulls[i] >> cows[i];
    Gen(0);
    if (ans == 0) cout << "Incorrect data\n";
    else if (ans == 1) {
            for (int i = 0; i < 4; i++) cout << saved[i];
            cout << endl;
         }
    else cout << "Need more data\n";
    return 0;
}