#include <iostream>
#include <set>
using namespace std;

const int Maxn = 100005;

int n;
int nims[Maxn];

int getNim(int a, int b)
{
    return nims[b] ^ nims[a - 1];
}

int main()
{
    cin >> n;
    for (int i = 3; i <= n; i++) {
        set <int> S;
        for (int k = 2; k * (k - 1) < 2 * i; k++) {
            int sum = 2 * i - k * (k - 1);
            if (sum % (2 * k) == 0) {
                    int first = sum / (2 * k);
                    S.insert(getNim(first, first + k - 1));
            }
        }
        int res = 0;
        while (S.find(res) != S.end()) res++;
        nims[i] = nims[i - 1] ^ res;
    }
    if (getNim(n, n) == 0) cout << "-1\n";
    else {
         int res = 1;
         do {
             res++;
             int sum = 2 * n - res * (res - 1);
             if (sum % (2 * res)) continue;
             int first = sum / (2 * res);
             if (getNim(first, first + res - 1) == 0) break;
         } while (true);
         cout << res << endl;
    }
    return 0;
}