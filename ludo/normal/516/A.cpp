#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 1000

typedef long long ll;
typedef pair<int, int> pii;

int max_n, n = 0;
int digits[MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> max_n;
    for (int i = 0; i < max_n; i++) {
        char ch; cin >> ch;
        if (ch != '0' && ch != '1') {
            digits[n++] = ch - '0';
        }
    }

    // 689: 10534551552000
    // 3456 * 25401600 * 120 = 10534551552000

//    for (int i = 0; i < n; i++) {
//        cout << digits[i] << " ";
//    }
//    cout << endl;

    for (int i = 0; i < n; i++) {
        if (digits[i] == 4) {
            digits[i] = 3;
            digits[n++] = 2;
            digits[n++] = 2;
        } else if (digits[i] == 6) {
            digits[i] = 5;
            digits[n++] = 3;
        } else if (digits[i] == 8) {
            digits[i] = 7;
            digits[n++] = 2;
            digits[n++] = 2;
            digits[n++] = 2;
        } else if (digits[i] == 9) {
            digits[i] = 7;
            digits[n++] = 3;
            digits[n++] = 3;
            digits[n++] = 2;
        }
    }

    sort(digits, digits + n);

//    cout << n << endl;

    while(n-- > 0) {
        cout << digits[n];
    }
    cout << endl;
    return 0;
}