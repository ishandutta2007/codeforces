#include <iostream>
using namespace std;

const int Inf = 1000000000;

int n;
int best = Inf;
int bx, by;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int x = 0; 4 * x <= n; x++) {
        int lft = n - 4 * x;
        if (lft % 7 == 0) {
                int y = lft / 7;
                if (x + y <= best) {
                      best = x + y;
                      bx = x; by = y;
                }
        }
    }
    if (best == Inf) cout << "-1\n";
    else {
         for (int i = 0; i < bx; i++) cout << '4';
         for (int i = 0; i < by; i++) cout << '7';
         cout << endl;
    }
    return 0;
}