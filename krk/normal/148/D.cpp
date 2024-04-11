#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 1005;
const ld eps = 1e-12;

int w, b;
ld res[Maxn][Maxn][2];

ld getProb(int w, int b, int pl)
{
    if (w < 0 || b < 0) return 0.0L;
    if (w == 0) return pl == 0? 0.0L: 1.0L;
    if (b == 0) return 1.0L;
    if (res[w][b][pl] < 0.0L)
       if (pl == 0) res[w][b][pl] = double(w) / double(w + b) + 
                                    double(b) / double(w + b) * (1.0L - getProb(w, b - 1, 1));
       else res[w][b][pl] = double(w) / double(w + b) +
                            double (b) / double(w + b) * 
                            (double(w) / double(w + b - 1) * (1.0L - getProb(w - 1, b - 1, 0)) +
                             double(b - 1) / double(w + b - 1) * (1.0L - getProb(w, b - 2, 0)));
    return res[w][b][pl];
}

int main()
{
    fill((ld*)res, (ld*)res + Maxn * Maxn * 2, -1.0L);
    cin >> w >> b;
    cout << fixed << setprecision(11) << getProb(w, b, 0) + eps << endl;
    return 0;
}