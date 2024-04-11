#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n, a[N], kol[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i1 = 1; i1 <= n; i1++)
        for (int j1 = 1; j1 <= n; j1++) {
            int x = a[i1], y = a[j1];
            for (int i = 1; i <= n; i++)
                kol[a[i]]++;
            bool r = 1;
            for (int i = 1; i * i <= x; i++)
            if (x % i == 0)
            {
                kol[i]--;
                if (i * i != x)
                    kol[x / i]--;
                if (kol[i] < 0 || kol[x / i] < 0)
                    r = 0;
            }
            for (int i = 1; i * i <= y; i++)
            if (y % i == 0)
            {
                kol[i]--;
                if (i * i != y)
                    kol[y / i]--;
                if (kol[i] < 0 || kol[y / i] < 0)
                    r = 0;
            }
            for (int i = 1; i <= n; i++)
                if (kol[a[i]] != 0)
                    r = 0, kol[a[i]] = 0;

            if (r) {
                cout << x << ' '<<y << endl;
                return 0;
            }
        }
    return 0;
}