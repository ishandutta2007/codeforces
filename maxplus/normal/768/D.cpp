#include <iostream>
#include <cfloat>

using namespace std;

const int N = 10001, M = 1002;
long double prob[N][M], dbg;
const long double eps = 1e-7;

int main()
{
    int k = 1000, q = 0, p;
    cin >> k >> q;
    prob[0][0] = 1;
    for (int i = 0; i + 1 < N; ++i)
        for (int j = 0; j <= k; ++j)
            prob[i + 1][j] += prob[i][j] * j / k,
            prob[i + 1][j + 1] += prob[i][j] * (k - j) / k;
    while (q-- && cin >> p)
        for (int i = 0; i < N; ++i)
            if (prob[i][k] >= (p - eps / 2) / 2000)
                cout << i << '\n', i = N;
    return 0;
}