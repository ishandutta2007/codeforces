#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

const int M = 1000000007;
const int N = 16;

int d[1 << N][4];

int main() {
    int n, T;
    cin >> n >> T;
    vector<int> durs(n), types(n);
    forn(i, n) {
        cin >> durs[i] >> types[i];
        types[i]--;
    }

    int result = 0;
    d[0][3] = 1;
    forn(mask, 1 << n)
        forn(lst, 4) {
            forn(j, n)
                if (types[j] != lst && ((mask & (1 << j)) == 0))
                    d[mask ^ (1 << j)][types[j]] = (d[mask ^ (1 << j)][types[j]] + d[mask][lst]) % M;
            int sum = 0;
            forn(i, n)
                if (mask & (1 << i))
                    sum += durs[i];
            if (sum == T)
                result = (result + d[mask][lst]) % M;
        }

    cout << result << endl;
}