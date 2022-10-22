#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    int k = 0;
    while (k * (k + 1) / 2 <= n) k++;
    cout << k << endl;
    for (int l = 0; l < k; l++) {
        int need = 1;
        bool printed = false;
        for (int i = 0; i < k; i++)
            for (int j = i + 1; j < k; j++) {
                if (i == l) {
                      if (printed) cout << " ";
                      cout << need; printed = true;
                }
                if (j == l) {
                      if (printed) cout << " ";
                      cout << need; printed = true;
                }
                need++;
            }
         cout   << endl;
    }
    return 0;
}