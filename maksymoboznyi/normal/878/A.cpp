#include <iostream>
#define orrr klfzjsgr
#define xorrr fewje
#define andd fefowjg

using namespace std;

const int N = 5e5 + 5;

int n, v[N];
char c[N];


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> v[i];
    int orr = 0, xorr = 0, andd = 0;
    for (int bit = 0; bit < 10; bit++) {
        bool is_change = 0;
        int real = -1;
        for (int i = 1; i <= n; i++) {
            if (c[i] == '|')
                if ((v[i] >> bit) & 1)
                    real = 1;
            if (c[i] == '&')
                if (!((v[i] >> bit) & 1))
                    real = 0;
            if (c[i] == '^')
                if ((v[i] >> bit) & 1)
                    if (real != -1)
                        real ^= 1;
                    else
                        is_change ^= 1;
        }
        if (real == -1)
        {
            if (is_change)
                xorr += (1 << bit);
            andd += (1 << bit);
        } else
            if (real == 0)
                continue;
            else
                orr += (1 << bit), andd += (1 << bit);
    }
    cout << "3\n| " << orr << "\n^ " << xorr << "\n& " << andd;
    return 0;
}