#include <iostream>

using namespace std;

typedef long long ll;

#define MAX 500

int n, m, b, mod, a[MAX], w[MAX + 1][MAX + 1];

int main()
{
    cin >> n >> m >> b >> mod;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    w[0][0] = 1;

    for (int i = 0; i < n; i++) {
        int cura = a[i];
//
//        int lasti = i & 1;
//        int curi = lasti ^ 1;



        for (int j = 1; j <= m; j++) {
            // j = current number of lines
            for (int k = cura; k <= b; k++) {
                // k = current number of bugs
                w[j][k] = (w[j][k] + w[j - 1][k - cura]) % mod;
            }
        }
//        for (int j = 0; j <= m; j++) {
//            cout << j << ": ";
//            for (int k = 0; k <= b; k++) {
//                cout << w[j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl << endl;
    }

    int ret = 0;
    for (int k = 0; k <= b; k++) {
        ret = (ret + w[m][k]) % mod;
    }
    cout << ret << endl;
    return 0;
}