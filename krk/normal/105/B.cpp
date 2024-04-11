#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 10;

int n, k;
int b[Maxn], l[Maxn];
int nl[Maxn];
int A, B;
double curres, res;

void Gen2(double pr, int lvl, int col)
{
     if (lvl == n) {
             if (col > n / 2) curres += pr;
             else curres += pr * double(A) / double(A + B);
             return;
     }
     Gen2(pr * double(nl[lvl]) / 100.0, lvl + 1, col + 1);
     B += b[lvl];
     Gen2(pr * (1.0 - double(nl[lvl]) / 100.0), lvl + 1, col);
     B -= b[lvl];
}

void Gen(int lvl, int lft)
{
     if (lvl == n) {
             curres = 0; B = 0;
             Gen2(1.0, 0, 0);
             res = max(res, curres);
             return;
     }
     for (int i = 0; i <= lft && l[lvl] + 10 * i <= 100; i++) {
         nl[lvl] = l[lvl] + 10 * i;
         Gen(lvl + 1, lft - i);
     }
}

int main()
{
    cin >> n >> k >> A;
    for (int i = 0; i < n; i++)
       cin >> b[i] >> l[i];
    Gen(0, k);
    cout << fixed << setprecision(10) << res + 1e-11 << endl;
    return 0;
}