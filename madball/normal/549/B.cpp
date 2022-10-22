#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
    /*ifstream in("input.txt");
    ofstream out("output.txt");*/

    ll n, i, j, k;
    char cur;
    cin >> n;
    vector<vector<bool> > listed(n, vector<bool>(n));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            cin >> cur;
            listed[i][j] = cur == '1';
        }

    vector<ll> guess(n);
    for (i = 0; i < n; i++)
        cin >> guess[i];

    vector<bool> came(n, false);
    ll res = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (!came[j] && !guess[j])
                break;
        if (j == n)
            break;
        came[j] = true;
        res++;
        for (k = 0; k < n; k++)
            if (listed[j][k])
                guess[k]--;
    }

    cout << res << '\n';
    for (i = 0; i < n; i++)
        if (came[i])
            cout << i + 1 << ' ';

    return 0;
}